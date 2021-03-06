%define lr.type canonical-lr
%define parse.error verbose
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>    
    #include "../lib/tabela.h"
    #include "../lib/arvore.h"
    #include "../lib/pilha.h"
    #include "../lib/semantic_utils.h"
    #include "../lib/tac.h"

    #define BRED "\e[0;31m"
    #define BMAG "\e[1;35m"
    #define BCYAN "\x1b[36m"
    #define RESET "\e[0m"

    extern int line;
    extern int columns;
    extern int errors;
    extern int yylex();
    extern int yylex_destroy();
    extern int yyparse();
    extern FILE* yyin;
    extern int scope;
    extern symbol symbol_table[100000];
    extern pilha scope_stack; 
    extern params param[100];
    extern int auxiliary_list[100000]; // No clue what this is doing atm, but if taken out it breaks the code.

    void yyerror(const char* msg);

    int tree_pointer = 0;
    int arg_counter = 0; // counts argument from function
    int param_counter = 0;
    // int param_counter_function = 0; // counts specific function argument;
    // int param_counter_args = 0; // counts specific function argument;
    int table_index = 0; // Indexes symbol_table;
    int table_size = 0; // Adds up by +1 when a new symbol is added on the symbol_table;
    tree* root; // First tree node(only reachable when the tree complete);

    // TAC Globals
    int string_idx = 0; // Variable to increment global string variables in TAC
    int reg_idx = 0; // Variable to incremental global register counter in TAC
    
%}  

%union{
    struct Token {
        int columns;
        int line;
        char body[101];
    } token;
    tree* node;
}

%token <token> SIMPLE_TYPE
%token <token> INT
%token <token> FLOAT
%token <token> LIST_TYPE
%token <token> LIST_CONSTANT    
%token <token> DIGIT
%token <token> STRING
%token <token> BINARY_BASIC_OP1
%token <token> BINARY_BASIC_OP2
%token <token> LOGIC_OP
%token <token> BINARY_COMP_OP
%token <token> KEYWORD
%token <token> INPUT
%token <token> OUTPUT
%token <token> BINARY_CONSTRUCTOR
%token <token> HEADER
%token <token> TAIL
%token <token> MAP
%token <token> FILTER
%token <token> ID
%token <token> IF
%token <token> ELSE
%token <token> FOR
%token <token> RETURN
%token <token> '=' '!' '(' ')' '{' '}'

%type <node> program
%type <node> declaration_list
%type <node> declaration
%type <node> var_declaration
%type <node> function_declaration
%type <node> list_declaration
%type <node> scope_declaration
%type <node> params_list
%type <node> params
%type <node> param
%type <node> if_else_stmt
%type <node> for_stmt
%type <node> return_stmt
%type <node> general_declaration
%type <node> multiple_stmt
%type <node> expression_stmt
%type <node> expression
%type <node> stmt
%type <node> simple_expression
%type <node> arithmetic_expression
%type <node> relational_expression
%type <node> list_operation
%type <node> term
%type <node> factor
%type <node> print
%type <node> scan
%type <node> for_variation_null_expressions
%type <node> unary_factor
%type <node> arguments_list
%type <node> arguments


%precedence ')'
%precedence '}'
%precedence ELSE    

%start program

%%
program: 
    declaration_list { 
        $$ = create_node("program");
        $$->node1 = $1;
        root = $$;
    }
;

declaration_list:
    declaration_list declaration {
        $$ = create_node("declaration_list");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | declaration {
        $$ = $1;
    }
;


declaration:
    var_declaration {$$ = $1;}
    | function_declaration {$$ = $1;} 
    | list_declaration {$$ = $1;}  
    | error {yyerrok;}
;

var_declaration:
    SIMPLE_TYPE ID ';' {
        int create;
        create = is_duplicated(symbol_table, $2.body, get_stack_top(&scope_stack), $2.line, $2.columns);
        if(create == 0){
            symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        $$ = create_node("var_declaration");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->node2->line = $2.line;
        $$->node2->column = $2.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack); 
        strcpy($$->node2->type, $1.body);
        assign_types($$->node2, symbol_table, &scope_stack); 

        if(strcmp($$->node2->type, "int") == 0 || strcmp($$->node2->type, "float") == 0){
            $$->is_symbol = 1;
            sprintf($$->tac_symbol, "%s %s_%d", $$->node2->type, $$->node2->type_name, $$->var_scope);
        }
    }
;

function_declaration:
    SIMPLE_TYPE ID '(' params_list ')' '{' multiple_stmt '}' {
        int create;
        create = is_duplicated(symbol_table, $2.body, get_stack_top(&scope_stack), $2.line, $2.columns);
        if(create == 0){
            symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 1, get_stack_top(&scope_stack));
            // printf("Current function: (%s) %s\n", $1.body, $2.body);
            new_symbol.function_params = param_counter;
            new_symbol.param = param;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;   
            param_counter = 0;
            // empty_params(param

        }
        $$ = create_node("function_declaration");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->node3 = $4;
        $$->node4 = $7;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->is_function = 1;
        $$->node2->line = $2.line;
        $$->node2->column = $2.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        strcpy($$->node2->type, $1.body);
        assign_types($$->node2, symbol_table, &scope_stack);
        if(errors == 0){
            search_return($$, "return", $$->node2->type); 
        }
    }
    | SIMPLE_TYPE LIST_TYPE ID '(' params_list ')' '{' multiple_stmt '}' {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, $3.body, get_stack_top(&scope_stack), $3.line, $3.columns);
        if(create == 0){   
            strcpy(str_simple_type, $1.body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, $2.body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 1, get_stack_top(&scope_stack));
            // printf("Current function: (%s) %s\n", list_string, $3.body);
            new_symbol.function_params = param_counter;
            new_symbol.param = param;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
            param_counter = 0;
        }
        
        $$ = create_node("function_declaration");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
        $$->node3 = $5;
        $$->node4 = $8;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->is_function = 1;
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);

        strcpy($$->node2->type, list_string);
        assign_types($$->node2, symbol_table, &scope_stack);
        if(errors == 0){
            search_return($$, "return", list_string);
        }

    }
;

list_declaration: 
    SIMPLE_TYPE LIST_TYPE ID ';' {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, $3.body, get_stack_top(&scope_stack), $3.line, $3.columns);
        if(create == 0){   
            strcpy(str_simple_type, $1.body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, $2.body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        $$ = create_node("list_declaration");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        
        strcpy($$->node2->type, list_string);
        assign_types($$->node2, symbol_table ,&scope_stack);
    }   
;

scope_declaration:
    '{' multiple_stmt '}' {
        $$ = create_node("scope_declaration");
        $$->node1 = $2;
        $$->var_scope = get_stack_top(&scope_stack);
    }
;

params_list: 
    params {$$ = $1;}
    | %empty {
        $$ = create_node("empty");
    }
;

params:
    params ',' param {
        $$ = create_node("params");
        $$->node1 = $1;
        $$->node2 = $3;

    } 
    | param {
        $$ = create_node("params");
        $$->node1 = $1;
    }   
    | error {yyerrok;}
;

param:
    SIMPLE_TYPE ID {
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, $2.body, get_stack_top(&scope_stack), $2.line, $2.columns);
        if(create == 0){    
            strcpy(param[param_counter].argument_type, $1.body);
            param_counter++;
            // printf(BCYAN"%s "RESET BMAG"%s\n"RESET, $1.body, $2.body);
            symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        $$ = create_node("param");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $2.line;
        $$->node2->column = $2.columns;
        strcpy($$->node2->type, $1.body);
        assign_types($$->node2, symbol_table, &scope_stack);
        $$->node2->var_scope = get_stack_top(&scope_stack);

        if(strcmp($$->node2->type, "int") == 0 || strcmp($$->node2->type, "float") == 0){
            $$->is_symbol = 1;
            sprintf($$->tac_symbol, "%s %s_%d", $$->node2->type, $$->node2->type_name, $$->var_scope);
        }

        pop(&scope_stack);
        scope--;
    }
    | SIMPLE_TYPE LIST_TYPE ID {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, $3.body, get_stack_top(&scope_stack), $3.line, $3.columns);
        if(create == 0){
            // Concatenating SIMPLE_TYPE + LIST_TYPE
            strcpy(str_simple_type, $1.body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, $2.body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            // End of concatenation
            strcpy(param[param_counter].argument_type, list_string);
            param_counter++;
            // printf(BCYAN"%s "RESET BMAG"%s\n"RESET, list_string, $3.body);
            symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        $$ = create_node("param");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        strcpy($$->node2->type, list_string);
        assign_types($$->node2, symbol_table, &scope_stack);

        if(strcmp($$->node2->type, "int list") == 0 || strcmp($$->node2->type, "float list") == 0){
            $$->is_symbol = 1;
            sprintf($$->tac_symbol, "%s %s_%d",  $$->node2->type, $$->node2->type_name, $$->var_scope);
        }

        pop(&scope_stack);
        scope--;
    }
;

if_else_stmt: 
    IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}' {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
        $$->node4 = create_node($8.body);
        $$->node5 = $10;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
        $$->node4 = create_node($8.body);
        $$->node5 = $9;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' stmt ELSE '{' multiple_stmt '}' {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = create_node($6.body);
        $$->node5 = $8;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' stmt ELSE stmt { 
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = create_node($6.body);
        $$->node5 = $7;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' '{' multiple_stmt '}' {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' stmt {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->line = $1.line;
        $$->column = $1.columns;    
    }
;

for_stmt:
    FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' '{' multiple_stmt '}' {
        $$ = create_node("for_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = $7;
        $$->node5 = $10;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' stmt {
        $$ = create_node("for_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = $7;
        $$->node5 = $9;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
;

return_stmt:
    RETURN ';' {$$ = create_node($1.body);} 
    | RETURN expression ';' {
        $$ = create_node($1.body);
        $$->node1 = $2;
        $$->line = $1.line;
        $$->column = $1.columns;

    }
;

general_declaration:
    general_declaration var_declaration {
        $$ = create_node("general_declaration");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | general_declaration list_declaration {
        $$ = create_node("general_declaration");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | general_declaration stmt {
        $$ = create_node("general_declaration");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | general_declaration scope_declaration{
        $$ = create_node("general_declaration");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | %empty {
        $$ = create_node("empty");
    }
;

multiple_stmt:
    general_declaration {$$ = $1;} 
;

expression_stmt:
    expression ';' {$$ = $1;}
;

for_variation_null_expressions:
    expression {$$ = $1;}
    | %empty {$$ = create_node("empty");}
;

stmt:
    expression_stmt {$$ = $1;}
    | if_else_stmt {$$ = $1;} 
    | for_stmt {$$ = $1;}
    | return_stmt {$$ = $1;} 
    | print {$$ = $1;}
    | scan {$$ = $1;}
    | error {yyerrok;}
;


print:
    OUTPUT '(' STRING ')' ';' {
        $$ = create_node("print");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($3.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        
        // TAC - Partially done. Still need to figure out how to print whole strings and pass it to '.code' section
        $$->is_symbol = 1;
        sprintf($$->tac_symbol, "char _str%d[] = %s", string_idx, $3.body);

        if(strcmp($$->node1->type_name, "write") == 0){
            sprintf($$->node1->tac_code, "print _str%d", string_idx);
        } else if(strcmp($$->node1->type_name, "writeln") == 0){
            sprintf($$->node1->tac_code, "println _str%d", string_idx);
        }


        string_idx++;
    }
    | OUTPUT '(' expression ')' ';' {
        $$ = create_node("print");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->line = $1.line;
        $$->column = $1.columns;
        evaluate_read_write($$, $$->node2);

        // TAC - Does not print complex expressions like: a*b*c
        if(strcmp($$->node1->type_name, "write") == 0 && $$->node2->is_const == 1){
            sprintf($$->node1->tac_code, "print %s", $$->node2->tac_const);
        } else if(strcmp($$->node1->type_name, "writeln") == 0 && $$->node2->is_const == 1){
            sprintf($$->node1->tac_code, "println %s", $$->node2->tac_const);
        }
    }
;

scan:
    INPUT '(' ID ')' ';' {
        $$ = create_node("scan");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($3.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        assign_types($$->node2, symbol_table, &scope_stack);
        search_undeclared_node($$->node2, symbol_table, &scope_stack);
        evaluate_read_write($$, $$->node2);

        // TAC - Done
        if(strcmp($$->node2->type, "int") == 0){
            sprintf($$->node1->tac_code, "scani %s_%d", $$->node2->type_name, $$->node2->var_scope);
        } else if(strcmp($$->node2->type, "float") == 0){
            sprintf($$->node1->tac_code, "scanf %s_%d", $$->node2->type_name, $$->node2->var_scope);
        }

    }
;

expression: 
    ID '=' expression {
        $$ = create_node("expression");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node1->line = $1.line;
        $$->node1->column = $1.columns;
        $$->node1->var_scope = get_stack_top(&scope_stack);
        search_undeclared_node($$->node1, symbol_table, &scope_stack);
        assign_types($$->node1, symbol_table, &scope_stack);
        evaluate_assignment($$->node1, $$, $$->node3);

        // printf("-------------------------------------------\n");       
        // printf(BCYAN"Node Name: %s\n" RESET, $$->type_name);
        // printf("Lside type: %s\n", $$->node1->type);
        // printf("Lside name: %s\n", $$->node1->type_name);        
        // printf("Rside type: %s\n", $$->node3->type);
        // printf("Rside name: %s\n", $$->node3->type_name);
        // // printf("ID: %s_%d\n", $1.body, $$->var_scope);
        // printf("Rside ID: %s\n", $$->node3->tac_const);
        // printf("-------------------------------------------\n");  

        // TAC - if right side is any ID, it generates 2 registers, otherwise it brings a temp register from another expression
        // List aren't being tested on this, skipping those types.
        if((strcmp($$->node1->type, "int list") != 0 && strcmp($$->node1->type, "float list") != 0) &&
            (strcmp($$->node3->type, "int list") != 0 && strcmp($$->node3->type, "float list") != 0)){
            if(strcmp($$->type, "") != 0){
                sprintf($$->node1->tac_const, "%s_%d", $1.body, $$->node1->var_scope);
                if($$->node3->is_const){
                    sprintf($$->tac_code, "mov %s, %s", $$->node1->tac_const, $$->node3->tac_const);
                } else {
                    sprintf($$->tac_code, "mov %s, $%d", $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        }
    } 
    | simple_expression {$$ = $1;}
    | error {yyerrok;}
;


simple_expression: 
    list_operation {$$ = $1;}
    | simple_expression LOGIC_OP list_operation {
        $$ = create_node("simple_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;
        
        evaluate_logical($$->node1, $$, $$->node3);

        // TAC - No casting is implemented
        $$->is_expression = 1;
        if(strcmp($$->node2->type_name, "&&") == 0){
            $$->tac_reg = reg_idx++;
            // Case: simple_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // simple_exp && ID
                    sprintf($$->tac_code, "and $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // simple_exp && simple_exp
                    sprintf($$->tac_code, "and $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID && ID
                    sprintf($$->tac_code, "and $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID && simple_ex
                    sprintf($$->tac_code, "and $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        } if(strcmp($$->node2->type_name, "||") == 0){
            $$->tac_reg = reg_idx++;
            // Case: simple_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // simple_exp || ID
                    sprintf($$->tac_code, "or $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // simple_exp || simple_exp
                    sprintf($$->tac_code, "or $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID || ID
                    sprintf($$->tac_code, "or $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID || simple_ex
                    sprintf($$->tac_code, "or $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        }
    }
;   


list_operation:
    relational_expression MAP list_operation {
        $$ = create_node("list_operation");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;

        evaluate_list_exp($$->node1, $$, $$->node3, $$->node2);

        // TAC - Nothing yet
        $$->is_expression = 1;
        // if(strcmp($$->node2->type_name) == 0){
        //     $$->tac_reg = reg_idx++;
        //     // Case: list_op(node1)
        //     if(!$$->node1->is_const){
        //         if($$->node3->is_const){ // list_op || ID
        //             sprintf($$->tac_code, "or $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
        //         } else { // list_op || list_op
        //             sprintf($$->tac_code, "or $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
        //         }
        //     } else { // Case ID(node1)
        //         if($$->node3->is_const){ // ID || ID
        //             sprintf($$->tac_code, "or $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
        //         } else { // ID || list_op
        //             sprintf($$->tac_code, "or $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
        //         }
        //     }
        // }

    }
    | relational_expression FILTER list_operation {
        $$ = create_node("list_operation");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;

        evaluate_list_exp($$->node1, $$, $$->node3, $$->node2);
        // TAC - Nothing yet
        $$->is_expression = 1;
        
    }
    | relational_expression BINARY_CONSTRUCTOR list_operation {
        $$ = create_node("list_operation");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;

        evaluate_list_exp($$->node1, $$, $$->node3, $$->node2);
        // TAC - Nothing yet
        $$->is_expression = 1;
    }
    | relational_expression {$$ = $1;}
;

 
relational_expression:
    relational_expression BINARY_COMP_OP arithmetic_expression {
        $$ = create_node("relational_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;
        evaluate_relational($$->node1, $$, $$->node3);

        // printf("-------------------------------------------\n");       
        // printf(BCYAN"RELATIONAL SCOPE: %d\n" RESET, $$->var_scope);
        // printf("RELATIONAL TYPE: %s\n", $$->type);
        // printf("LSide OP: %s\n", $$->node1->type_name);
        // printf("RSide OP: %s\n", $$->node3->type_name);
        // printf("Lside ID: %s\n", $$->node1->tac_const);
        // printf("Rside ID: %s\n", $$->node3->tac_const);
        // printf("Main node: %s\n", $$->type_name);
        // printf("-------------------------------------------\n");

        // TAC
        $$->is_expression = 1;
        if(strcmp($$->node2->type_name, "<") == 0){
            $$->tac_reg = reg_idx++;
            // Case: relational_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // relational_exp < ID
                    sprintf($$->tac_code, "slt $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // relational_exp < relational_exp
                    sprintf($$->tac_code, "slt $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID < ID
                    sprintf($$->tac_code, "slt $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID < relational_exp
                    sprintf($$->tac_code, "slt $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        } else if(strcmp($$->node2->type_name, "<=") == 0){
            $$->tac_reg = reg_idx++;
            // Case: relational_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // relational_exp <= ID
                    sprintf($$->tac_code, "sleq $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // relational_exp <= relational_exp
                    sprintf($$->tac_code, "sleq $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID <= ID
                    sprintf($$->tac_code, "sleq $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID <= relational_expArithmetic and relational exp done, still need to cast
                    sprintf($$->tac_code, "sleq $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        } else if(strcmp($$->node2->type_name, ">") == 0){
            $$->tac_reg = reg_idx++;
            // Case: relational_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // relational_exp (-1)<= ID
                    sprintf($$->tac_code, "sleq $%d, $%d, %s\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const, $$->tac_reg, $$->tac_reg);
                } else { // relational_exp (-1)<= relational_exp
                    sprintf($$->tac_code, "sleq $%d, $%d, $%d\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg, $$->tac_reg, $$->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID (-1)<= ID
                    sprintf($$->tac_code, "sleq $%d, %s, %s\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const, $$->tac_reg, $$->tac_reg);
                } else { // ID (-1)<= relational_exp
                    sprintf($$->tac_code, "sleq $%d, %s, $%d\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg, $$->tac_reg, $$->tac_reg);
                }
            }
        } else if(strcmp($$->node2->type_name, ">=") == 0){
            $$->tac_reg = reg_idx++;
            // Case: relational_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // relational_exp (-1) < ID
                    sprintf($$->tac_code, "slt $%d, $%d, %s\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const, $$->tac_reg, $$->tac_reg);
                } else { // relational_exp (-1)< relational_exp
                    sprintf($$->tac_code, "slt $%d, $%d, $%d\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg, $$->tac_reg, $$->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID (-1)< ID
                    sprintf($$->tac_code, "slt $%d, %s, %s\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const, $$->tac_reg, $$->tac_reg);
                } else { // ID (-1)< relational_exp
                    sprintf($$->tac_code, "slt $%d, %s, $%d\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg, $$->tac_reg, $$->tac_reg);
                }
            }
        } else if(strcmp($$->node2->type_name, "!=") == 0){
            $$->tac_reg = reg_idx++;
            // Case: relational_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // relational_exp (-1) == ID
                    sprintf($$->tac_code, "seq $%d, $%d, %s\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const, $$->tac_reg, $$->tac_reg);
                } else { // relational_exp (-1)== relational_exp
                    sprintf($$->tac_code, "seq $%d, $%d, $%d\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg, $$->tac_reg, $$->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID (-1)== ID
                    sprintf($$->tac_code, "seq $%d, %s, %s\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const, $$->tac_reg, $$->tac_reg);
                } else { // ID (-1)== relational_exp
                    sprintf($$->tac_code, "seq $%d, %s, $%d\nnot $%d, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg, $$->tac_reg, $$->tac_reg);
                }
            }
        } else if(strcmp($$->node2->type_name, "==") == 0){
            $$->tac_reg = reg_idx++;
            // Case: relational_exp(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // relational_exp == ID
                    sprintf($$->tac_code, "seq $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // relational_exp == relational_exp
                    sprintf($$->tac_code, "seq $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID == ID
                    sprintf($$->tac_code, "seq $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID == relational_exp
                    sprintf($$->tac_code, "seq $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        }
    }
    | arithmetic_expression {$$ = $1;}
;

arithmetic_expression:
    arithmetic_expression BINARY_BASIC_OP1 term {
        $$ = create_node("arithmetic_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;

        evaluate_arithmetic($$->node1, $$, $$->node3);

        // printf("-------------------------------------------\n");       
        // printf(BCYAN"ARITHMETIC SCOPE: %d\n" RESET, $$->var_scope);
        // printf("ARITHMETIC TYPE: %s\n", $$->type);
        // printf("LSide OP: %s\n", $$->node1->type_name);
        // printf("RSide OP: %s\n", $$->node3->type_name);
        // printf("Lside ID: %s\n", $$->node1->tac_const);
        // printf("Rside ID: %s\n", $$->node3->tac_const);
        // printf("Main node: %s\n", $$->type_name);
        // printf("-------------------------------------------\n");  


        // TAC - Almost done - Casting isn't done
        $$->is_expression = 1;
        printf("Node1: %s\n",$$->node1->type_name);
        printf("Node1 is const: %d\n",$$->node1->is_const);
        printf("Node2: %s\n",$$->node2->type_name);
        printf("Node3: %s\n",$$->node3->type_name);
        printf("Node3 is const: %d\n",$$->node3->is_const);
        if(strcmp($$->node2->type_name, "+") == 0){
            $$->tac_reg = reg_idx++;
            // Case: Arithmetic(node1) 
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // Arithmetic + ID
                    sprintf($$->tac_code, "add $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // Arithmetic + Arithmetic
                    sprintf($$->tac_code, "add $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // ID(node1)
                if($$->node3->is_const){ // ID + ID
                    sprintf($$->tac_code, "add $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID + Arithmetic
                    sprintf($$->tac_code, "add $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        } else if(strcmp($$->node2->type_name, "-") == 0){
            $$->tac_reg = reg_idx++;
            // Case: Arithmetic(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // Arithmetic - ID
                    sprintf($$->tac_code, "sub $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // Arithmetic - Arithmetic
                    sprintf($$->tac_code, "sub $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID - ID
                    sprintf($$->tac_code, "sub $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID - Arithmetic
                    sprintf($$->tac_code, "sub $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        }
    } 
    | term {$$ = $1;}
;

term: 
    term BINARY_BASIC_OP2 factor {
        $$ = create_node("term");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;

        evaluate_mult_div($$->node1, $$, $$->node3);

        // TAC - Almost done - No casting
        $$->is_expression = 1;
        if(strcmp($$->node2->type_name, "*") == 0){
            $$->tac_reg = reg_idx++;
            // Case: term(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // term * ID
                    sprintf($$->tac_code, "mul $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // term * term
                    sprintf($$->tac_code, "mul $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID + ID
                    sprintf($$->tac_code, "mul $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID + term
                    sprintf($$->tac_code, "mul $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        } else if(strcmp($$->node2->type_name, "/") == 0){
            $$->tac_reg = reg_idx++;
            // Case: term(node1)
            if(!$$->node1->is_const){
                if($$->node3->is_const){ // term / ID
                    sprintf($$->tac_code, "div $%d, $%d, %s", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_const);
                } else { // term / term
                    sprintf($$->tac_code, "div $%d, $%d, $%d", $$->tac_reg, $$->node1->tac_reg, $$->node3->tac_reg);
                }
            } else { // Case ID(node1)
                if($$->node3->is_const){ // ID / ID
                    sprintf($$->tac_code, "div $%d, %s, %s", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_const);
                } else { // ID / term
                    sprintf($$->tac_code, "div $%d, %s, $%d", $$->tac_reg, $$->node1->tac_const, $$->node3->tac_reg);
                }
            }
        }

    }
    | factor {$$ = $1;}
;

factor:
    '(' expression ')' {$$ = $2;} 
    | ID {
        $$ = create_node($1.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $1.line;
        $$->column = $1.columns;
        search_undeclared_node($$, symbol_table, &scope_stack);
        assign_types($$, symbol_table, &scope_stack);


        // TAC
        $$->is_const = 1;
        sprintf($$->tac_const, "%s_%d", $1.body, $$->var_scope);
        // printf("-------------------------------------------\n");       
        // printf(BCYAN"FACTOR 'ID_SCOPE': %s\n" RESET, $$->tac_const);
        // printf("FACTOR TYPE: %s\n", $$->type);

        // printf("-------------------------------------------\n");       
    }
    | INT {
        $$ = create_node($1.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        strcpy($$->type, "int"); 
        
        // TAC
        $$->is_const = 1;
        strcpy($$->tac_const, $$->type_name);
    }
    | FLOAT {
        $$ = create_node($1.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        strcpy($$->type, "float");

        // TAC
        $$->is_const = 1;
        strcpy($$->tac_const, $$->type_name);
    }
    | ID '(' arguments_list ')' {
        $$ = create_node("factor_arguments");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node1->var_scope = get_stack_top(&scope_stack);
        $$->node1->line = $1.line;
        $$->node1->column = $1.columns;
        function_param_amount(symbol_table,arg_counter,$1.body, $1.line, $1.columns);
        arg_counter = 0;
        search_undeclared_node($$->node1, symbol_table, &scope_stack);
        assign_types($$->node1, symbol_table, &scope_stack);
    } 
    | LIST_CONSTANT {
        $$ = create_node($1.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        strcpy($$->type, "NIL");
    }
    | unary_factor {$$ = $1;}
;

arguments:
    arguments_list ',' expression {
        $$ = create_node("arguments");
        $$->node1 = $1;
        $$->node2 = $3; 
        arg_counter++;
    } 
    | expression {
        $$ = create_node("arguments");
        $$->node1 = $1;
        arg_counter++;
    }
;

arguments_list: 
    arguments {$$ = $1;}
    | %empty {
        $$ = create_node("empty");
    }
;

unary_factor:
    BINARY_BASIC_OP1 factor {
        $$ = create_node("unary_factor");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $1.line;
        $$->column = $1.columns;

        evaluate_unary($$->node1, $$, $$->node2);
    }
    | TAIL factor{
        $$ = create_node("unary_factor");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $1.line;
        $$->column = $1.columns;

        evaluate_unary($$->node1, $$, $$->node2);
    } 
    | HEADER factor{
        $$ = create_node("unary_factor");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $1.line;
        $$->column = $1.columns;

        evaluate_unary($$->node1, $$, $$->node2);
    } 
;

%%

void yyerror(const char* msg){
    printf(BRED"(%d|%d) ", line, columns);
    printf("Syntax error: ");
    printf("%s\n"RESET, msg);
    errors++;
}

void new_tac_file(){
    FILE *fp = fopen("output.tac", "w+");
    if(fp){
        // Symbol table
        fprintf (fp, ".table\n");
        write_symbol_table(root, fp);
        // Effective Code
        fprintf (fp, "\n.code\n");
        write_code(root, fp);
    }
    else{
        printf("Error, could not write TAC file.\n");
    }
    fclose(fp);
}

int main(int argc, char ** argv) {
    init_stack(&scope_stack);
    init_aux_list(auxiliary_list);
    FILE *fp = fopen(argv[1], "r");
    if(argc > 1) {
        if(fp) {
            yyin = fp;
            yyparse();
        }
        else {
            printf("File does not exist.\n");
        }
    }
    else {
        printf("No input given.\n");
    }
    
    main_detection(table_size);
    print_table(table_size);
    if(errors == 0){
        printf(BCYAN"No sintatic errors detected. Printing tree and throwing possible semantic errors.\n" RESET);
        print_tree(root, 0);
        new_tac_file();
        free_node(root);
    }
    fclose(yyin);    
    yylex_destroy();

    return 0;
}