/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "src/sintatico.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>    
    #include "../lib/tabela.h"
    #include "../lib/arvore.h"
    #include "../lib/pilha.h"
    #include "../lib/semantic_utils.h"

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
    

#line 111 "src/sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SIMPLE_TYPE = 3,                /* SIMPLE_TYPE  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_LIST_TYPE = 6,                  /* LIST_TYPE  */
  YYSYMBOL_LIST_CONSTANT = 7,              /* LIST_CONSTANT  */
  YYSYMBOL_DIGIT = 8,                      /* DIGIT  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_BINARY_BASIC_OP1 = 10,          /* BINARY_BASIC_OP1  */
  YYSYMBOL_BINARY_BASIC_OP2 = 11,          /* BINARY_BASIC_OP2  */
  YYSYMBOL_LOGIC_OP = 12,                  /* LOGIC_OP  */
  YYSYMBOL_BINARY_COMP_OP = 13,            /* BINARY_COMP_OP  */
  YYSYMBOL_KEYWORD = 14,                   /* KEYWORD  */
  YYSYMBOL_INPUT = 15,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 16,                    /* OUTPUT  */
  YYSYMBOL_BINARY_CONSTRUCTOR = 17,        /* BINARY_CONSTRUCTOR  */
  YYSYMBOL_HEADER = 18,                    /* HEADER  */
  YYSYMBOL_TAIL = 19,                      /* TAIL  */
  YYSYMBOL_MAP = 20,                       /* MAP  */
  YYSYMBOL_FILTER = 21,                    /* FILTER  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '!'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_declaration_list = 37,          /* declaration_list  */
  YYSYMBOL_declaration = 38,               /* declaration  */
  YYSYMBOL_var_declaration = 39,           /* var_declaration  */
  YYSYMBOL_function_declaration = 40,      /* function_declaration  */
  YYSYMBOL_list_declaration = 41,          /* list_declaration  */
  YYSYMBOL_scope_declaration = 42,         /* scope_declaration  */
  YYSYMBOL_params_list = 43,               /* params_list  */
  YYSYMBOL_params = 44,                    /* params  */
  YYSYMBOL_param = 45,                     /* param  */
  YYSYMBOL_if_else_stmt = 46,              /* if_else_stmt  */
  YYSYMBOL_for_stmt = 47,                  /* for_stmt  */
  YYSYMBOL_return_stmt = 48,               /* return_stmt  */
  YYSYMBOL_general_declaration = 49,       /* general_declaration  */
  YYSYMBOL_multiple_stmt = 50,             /* multiple_stmt  */
  YYSYMBOL_expression_stmt = 51,           /* expression_stmt  */
  YYSYMBOL_for_variation_null_expressions = 52, /* for_variation_null_expressions  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_print = 54,                     /* print  */
  YYSYMBOL_scan = 55,                      /* scan  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_simple_expression = 57,         /* simple_expression  */
  YYSYMBOL_list_operation = 58,            /* list_operation  */
  YYSYMBOL_relational_expression = 59,     /* relational_expression  */
  YYSYMBOL_arithmetic_expression = 60,     /* arithmetic_expression  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_arguments = 63,                 /* arguments  */
  YYSYMBOL_arguments_list = 64,            /* arguments_list  */
  YYSYMBOL_unary_factor = 65               /* unary_factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,     2,     2,     2,     2,     2,
      29,    30,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   126,   131,   138,   139,   140,   141,   145,
     170,   201,   243,   274,   282,   283,   289,   295,   299,   303,
     329,   368,   378,   388,   398,   408,   416,   427,   437,   450,
     451,   461,   466,   471,   476,   481,   487,   491,   495,   496,
     500,   501,   502,   503,   504,   505,   506,   511,   518,   529,
     546,   560,   561,   566,   567,   582,   593,   604,   615,   620,
     630,   634,   645,   649,   660,   664,   665,   673,   680,   687,
     700,   707,   711,   717,   725,   726,   732,   742,   752
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SIMPLE_TYPE", "INT",
  "FLOAT", "LIST_TYPE", "LIST_CONSTANT", "DIGIT", "STRING",
  "BINARY_BASIC_OP1", "BINARY_BASIC_OP2", "LOGIC_OP", "BINARY_COMP_OP",
  "KEYWORD", "INPUT", "OUTPUT", "BINARY_CONSTRUCTOR", "HEADER", "TAIL",
  "MAP", "FILTER", "ID", "IF", "ELSE", "FOR", "RETURN", "'='", "'!'",
  "'('", "')'", "'{'", "'}'", "';'", "','", "$accept", "program",
  "declaration_list", "declaration", "var_declaration",
  "function_declaration", "list_declaration", "scope_declaration",
  "params_list", "params", "param", "if_else_stmt", "for_stmt",
  "return_stmt", "general_declaration", "multiple_stmt", "expression_stmt",
  "for_variation_null_expressions", "stmt", "print", "scan", "expression",
  "simple_expression", "list_operation", "relational_expression",
  "arithmetic_expression", "term", "factor", "arguments", "arguments_list",
  "unary_factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    33,    40,
      41,   123,   125,    59,    44
};
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,   300,    -5,    13,   334,   370,   375,   398,   458,    15,
      70,  -196,   478,    99,     2,   497,     2,   501,    22,    84,
      16,   101,   186,    41,    71,   189,    65,    98,   103,   216,
    1464,   233,  1464,  1496,   108,   110,   727,   133,  2760,  2774,
    2788,  2498,   137,   138,  2498,  2498,  2736,   148,   149,    76,
     335,  1464,  1528,  1560,  1592,  1624,  1656,  1688,  1720,  1752,
    1784,  1816,   155,    -8,    -4,   390,  2942,  2802,  2816,  2830,
     517,   536,   181,   169,   339,  2844,   182,   386,  2858,  2872,
    2466,    44,   335,   208,   192,  1848,   195,   201,   190,  1880,
    2498,  2498,  2498,  2498,  2498,  2498,  2498,   207,   217,   218,
     219,   231,   239,   247,   252,   225,   237,   271,  1912,  2886,
    1944,    -2,  2956,     8,     9,    14,  2900,  2914,   274,   282,
     284,  2928,  2482,   509,   208,  1976,  2008,  2040,   254,  1464,
     760,   285,   240,   544,  2434,   792,  1464,  2072,   291,   600,
     264,  2319,  1464,  2104,  2136,  1464,  2168,   297,   301,  2200,
    2232,   308,  2984,  2996,  3008,  2514,  2514,  2514,   433,   335,
      57,   129,  2545,  3140,  3020,  3032,  3044,  2264,   255,   180,
    2574,  2586,  2530,  2530,  2530,  2534,   335,    58,    95,   222,
      23,  2601,  2613,  2628,  2296,   694,   312,   317,   326,   329,
     261,   824,   856,   888,   920,   952,   984,   330,   332,  2970,
    3056,  3068,  3080,   335,    44,   344,  2514,  2514,  2514,  2514,
    2514,  2514,  2514,  2559,  2640,  2655,  2667,  2482,    44,   349,
    2530,  2530,  2530,  2530,  2530,  2530,  2530,   358,  2450,   335,
     208,  1016,   348,  1048,   355,   263,  3092,   150,  3152,   159,
     164,   175,  3104,  3116,   265,   268,  2682,   115,    55,   139,
     187,   199,  2694,  2709,   359,   362,   364,   367,   373,  1080,
    3128,  2721,   376,   379,   393,  2342,   208,  1112,  1144,  1176,
    1464,  1208,   396,   405,  2365,  2434,  1240,  1464,  1272,   410,
    2388,   409,  2411,  1464,  1304,  1336,  1464,  1368,   415,   416,
    1400,  1432
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,   445,   419,  -196,   424,  -196,   449,  -196,
     444,   -19,   -18,   -15,  -196,   -32,    -3,  -122,  -117,    17,
      31,   -22,   -43,   374,   465,   430,   266,   102,  -196,  -195,
     210
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    54,    20,    21,
      22,   191,   192,   193,    33,    34,   194,   106,    59,   195,
     196,   197,    63,    64,    65,    66,    67,    68,   103,   104,
      69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,     9,   131,    18,    90,    19,   130,   160,   -53,   235,
     -54,    62,   138,    11,    55,    56,   137,    10,    57,    88,
     -57,   -55,   143,   245,   146,   -51,   -56,    86,    87,   -53,
      58,   -54,   -15,   225,   160,   -60,   -60,    13,   177,   160,
     -60,   -57,   -55,   -60,   -60,   168,    26,   -56,   169,   170,
      60,   171,   -18,   -60,   172,   100,   -18,   -60,   101,   102,
     105,   107,   173,   174,    61,   225,   175,   -59,   -59,   206,
     220,    28,   -59,   176,   -75,   -59,   -59,    84,   -75,   177,
      38,    39,     1,    40,     2,   -59,    41,   -51,   -51,   -59,
      24,   160,   -51,    29,    44,    45,    30,   132,    46,    14,
     128,    19,   107,    15,   140,    50,    25,   -53,   258,    85,
     147,    62,   198,   148,    55,    56,   160,    62,    57,    62,
      55,    56,    55,    56,    57,   -53,    57,   -54,    16,   -53,
      58,   -14,    17,   160,    32,    27,    58,   205,    58,    72,
      70,   -53,    71,    75,   272,   -54,    78,    79,   271,   -54,
      60,   -57,   165,   279,   219,    73,    60,   278,    60,   -53,
     160,   177,   -54,   284,    61,   287,    76,    77,   232,   -57,
      61,   -57,    61,   -57,   177,   177,   -55,    82,    83,   165,
     -54,   234,   102,   182,   165,   160,   160,   -56,    89,   -57,
     -67,   -67,   -67,   -67,   -55,   244,   102,   -67,   117,   -55,
     -67,   -67,   167,    97,    98,   -56,   256,   257,   107,    84,
     -67,   -56,    38,    39,   -67,    40,   -17,   -55,    41,   -19,
     -17,   -55,   110,   -19,   182,   -52,    44,    45,   108,   -56,
      46,   109,   160,   -56,   -58,   221,   165,    50,   273,   222,
     184,   -39,   223,   224,   107,   281,   -20,   118,   119,   120,
     -20,   288,   -58,   198,   289,   123,   -58,   200,   201,   202,
     166,   165,    84,   -16,   -50,    38,    39,   -16,    40,   -73,
     124,    41,   135,   -73,   214,   215,   216,   -74,   165,    44,
      45,   -74,   121,    46,   -72,   -52,   122,   166,   -72,   -52,
      50,   183,   166,   260,   231,   -50,   144,   122,   261,   -50,
      -8,    -8,   122,    -8,   -38,   165,   182,   125,   165,   165,
     165,   165,   165,   165,   243,   126,   164,   127,   134,   182,
     182,   141,   182,   182,   182,   182,   182,   182,   253,   149,
     165,   165,   183,   150,    -2,     1,   151,     2,   -52,   152,
     153,   227,   154,   164,   166,   155,   228,   181,   164,   -66,
     -66,   -66,   -66,   156,   157,   229,   -66,   158,   230,   -66,
     -66,   116,   -38,   233,   159,   166,   166,   166,    81,   166,
      -4,    -4,   -66,    -4,   236,    -5,    -5,   165,    -5,   246,
     254,   259,   183,   183,   183,   -50,   166,   151,   181,   262,
     152,   153,   263,   154,   264,    99,   155,   265,    -6,    -6,
     164,    -6,   -58,    91,   156,   157,   266,    92,   158,   267,
      93,    94,   268,   166,   183,   159,   166,   166,   166,   166,
     166,   166,   166,   -58,   161,   164,   269,   183,   183,   275,
     183,   183,   183,   183,   183,   183,   183,   276,   166,   166,
     282,   285,   164,   -66,   -66,   -66,   -66,   290,   291,    12,
     -66,   161,    52,   -66,   -66,   178,   161,    53,    -7,    -7,
     203,    -7,   204,   -66,   111,    23,   113,   114,   115,   164,
     181,    31,   164,   164,   164,   164,   164,   242,    -3,    -3,
     163,    -3,     0,   181,   181,   166,   181,   181,   181,   181,
     181,   252,     0,     0,   164,   164,   178,    -9,    -9,     0,
      -9,   -12,   -12,     0,   -12,     0,     0,   163,   161,     0,
     185,   180,   163,    38,    39,   162,    40,   -10,   -10,    41,
     -10,   112,     0,     0,   186,   187,     0,    44,    45,     0,
       0,    46,   188,   161,   189,   190,   -11,   -11,    50,   -11,
     129,   164,   162,     0,     0,    36,   179,   162,    38,    39,
     161,    40,   180,     0,    41,     0,     0,     0,     0,    42,
      43,     0,    44,    45,   163,     0,    46,    47,     0,    48,
      49,     0,     0,    50,     0,   136,     0,   161,   178,     0,
     237,     0,   239,   240,   241,     0,     0,   179,     0,   163,
       0,   178,   178,     0,   247,     0,   249,   250,   251,   162,
       0,    36,   161,   161,    38,    39,   163,    40,     0,     0,
      41,     0,     0,     0,     0,    42,    43,     0,    44,    45,
       0,     0,    46,    47,   162,    48,    49,     0,     0,    50,
       0,   142,     0,   163,   180,     0,   163,   238,   163,   163,
     163,   162,     0,     0,     0,     0,     0,   180,   180,   161,
     180,   248,   180,   180,   180,     0,     0,     0,   163,   163,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   179,
       0,   162,     0,   162,   162,   162,     0,     0,     0,     0,
       0,     0,   179,   179,     0,   179,     0,   179,   179,   179,
       0,     0,     0,   162,   162,   -46,     0,   -46,   -46,   -46,
       0,   -46,     0,     0,   -46,   163,     0,     0,     0,   -46,
     -46,     0,   -46,   -46,     0,     0,   -46,   -46,   -46,   -46,
     -46,     0,     0,   -46,     0,   -46,   -46,   -52,   -46,     0,
     -46,   -46,   -46,     0,   -46,     0,     0,   -46,     0,     0,
     162,     0,   -46,   -46,     0,   -46,   -46,     0,     0,   -46,
     -46,     0,   -46,   -46,     0,     0,   -46,     0,   -46,   -46,
     -52,   -26,     0,   -26,   -26,   -26,     0,   -26,     0,     0,
     -26,     0,     0,     0,     0,   -26,   -26,     0,   -26,   -26,
       0,     0,   -26,   -26,   133,   -26,   -26,     0,     0,   -26,
       0,   -26,   -26,   -25,     0,   -25,   -25,   -25,     0,   -25,
       0,     0,   -25,     0,     0,     0,     0,   -25,   -25,     0,
     -25,   -25,     0,     0,   -25,   -25,   139,   -25,   -25,     0,
       0,   -25,     0,   -25,   -25,   -41,     0,   -41,   -41,   -41,
       0,   -41,     0,     0,   -41,     0,     0,     0,     0,   -41,
     -41,     0,   -41,   -41,     0,     0,   -41,   -41,   -41,   -41,
     -41,     0,     0,   -41,     0,   -41,   -41,   -42,     0,   -42,
     -42,   -42,     0,   -42,     0,     0,   -42,     0,     0,     0,
       0,   -42,   -42,     0,   -42,   -42,     0,     0,   -42,   -42,
     -42,   -42,   -42,     0,     0,   -42,     0,   -42,   -42,   -43,
       0,   -43,   -43,   -43,     0,   -43,     0,     0,   -43,     0,
       0,     0,     0,   -43,   -43,     0,   -43,   -43,     0,     0,
     -43,   -43,   -43,   -43,   -43,     0,     0,   -43,     0,   -43,
     -43,   -40,     0,   -40,   -40,   -40,     0,   -40,     0,     0,
     -40,     0,     0,     0,     0,   -40,   -40,     0,   -40,   -40,
       0,     0,   -40,   -40,   -40,   -40,   -40,     0,     0,   -40,
       0,   -40,   -40,   -44,     0,   -44,   -44,   -44,     0,   -44,
       0,     0,   -44,     0,     0,     0,     0,   -44,   -44,     0,
     -44,   -44,     0,     0,   -44,   -44,   -44,   -44,   -44,     0,
       0,   -44,     0,   -44,   -44,   -45,     0,   -45,   -45,   -45,
       0,   -45,     0,     0,   -45,     0,     0,     0,     0,   -45,
     -45,     0,   -45,   -45,     0,     0,   -45,   -45,   -45,   -45,
     -45,     0,     0,   -45,     0,   -45,   -45,   -29,     0,   -29,
     -29,   -29,     0,   -29,     0,     0,   -29,     0,     0,     0,
       0,   -29,   -29,     0,   -29,   -29,     0,     0,   -29,   -29,
     -29,   -29,   -29,     0,     0,   -29,     0,   -29,   -29,   -37,
       0,   -37,   -37,   -37,     0,   -37,     0,     0,   -37,     0,
       0,     0,     0,   -37,   -37,     0,   -37,   -37,     0,     0,
     -37,   -37,   -37,   -37,   -37,     0,     0,   -37,     0,   -37,
     -37,   -30,     0,   -30,   -30,   -30,     0,   -30,     0,     0,
     -30,     0,     0,     0,     0,   -30,   -30,     0,   -30,   -30,
       0,     0,   -30,   -30,   -30,   -30,   -30,     0,     0,   -30,
       0,   -30,   -30,   -49,     0,   -49,   -49,   -49,     0,   -49,
       0,     0,   -49,     0,     0,     0,     0,   -49,   -49,     0,
     -49,   -49,     0,     0,   -49,   -49,   -49,   -49,   -49,     0,
       0,   -49,     0,   -49,   -49,   -47,     0,   -47,   -47,   -47,
       0,   -47,     0,     0,   -47,     0,     0,     0,     0,   -47,
     -47,     0,   -47,   -47,     0,     0,   -47,   -47,   -47,   -47,
     -47,     0,     0,   -47,     0,   -47,   -47,   -48,     0,   -48,
     -48,   -48,     0,   -48,     0,     0,   -48,     0,     0,     0,
       0,   -48,   -48,     0,   -48,   -48,     0,     0,   -48,   -48,
     -48,   -48,   -48,     0,     0,   -48,     0,   -48,   -48,   -26,
       0,   -26,   -26,   -26,     0,   -26,     0,     0,   -26,     0,
       0,     0,     0,   -26,   -26,     0,   -26,   -26,     0,     0,
     -26,   -26,   274,   -26,   -26,     0,     0,   -26,     0,   -26,
     -26,   -25,     0,   -25,   -25,   -25,     0,   -25,     0,     0,
     -25,     0,     0,     0,     0,   -25,   -25,     0,   -25,   -25,
       0,     0,   -25,   -25,   280,   -25,   -25,     0,     0,   -25,
       0,   -25,   -25,   -24,     0,   -24,   -24,   -24,     0,   -24,
       0,     0,   -24,     0,     0,     0,     0,   -24,   -24,     0,
     -24,   -24,     0,     0,   -24,   -24,   -24,   -24,   -24,     0,
       0,   -24,     0,   -24,   -24,   -22,     0,   -22,   -22,   -22,
       0,   -22,     0,     0,   -22,     0,     0,     0,     0,   -22,
     -22,     0,   -22,   -22,     0,     0,   -22,   -22,   -22,   -22,
     -22,     0,     0,   -22,     0,   -22,   -22,   -23,     0,   -23,
     -23,   -23,     0,   -23,     0,     0,   -23,     0,     0,     0,
       0,   -23,   -23,     0,   -23,   -23,     0,     0,   -23,   -23,
     -23,   -23,   -23,     0,     0,   -23,     0,   -23,   -23,   -28,
       0,   -28,   -28,   -28,     0,   -28,     0,     0,   -28,     0,
       0,     0,     0,   -28,   -28,     0,   -28,   -28,     0,     0,
     -28,   -28,   -28,   -28,   -28,     0,     0,   -28,     0,   -28,
     -28,   -21,     0,   -21,   -21,   -21,     0,   -21,     0,     0,
     -21,     0,     0,     0,     0,   -21,   -21,     0,   -21,   -21,
       0,     0,   -21,   -21,   -21,   -21,   -21,     0,     0,   -21,
       0,   -21,   -21,   -27,     0,   -27,   -27,   -27,     0,   -27,
       0,     0,   -27,     0,     0,     0,     0,   -27,   -27,     0,
     -27,   -27,     0,     0,   -27,   -27,   -27,   -27,   -27,     0,
       0,   -27,     0,   -27,   -27,   -35,     0,   -35,   -35,   -35,
       0,   -35,     0,     0,   -35,     0,     0,     0,     0,   -35,
     -35,     0,   -35,   -35,     0,     0,   -35,   -35,     0,   -35,
     -35,     0,     0,   -35,     0,   -35,   -35,    36,     0,    37,
      38,    39,     0,    40,     0,     0,    41,     0,     0,     0,
       0,    42,    43,     0,    44,    45,     0,     0,    46,    47,
       0,    48,    49,     0,     0,    50,     0,    51,   -36,   -31,
       0,   -31,   -31,   -31,     0,   -31,     0,     0,   -31,     0,
       0,     0,     0,   -31,   -31,     0,   -31,   -31,     0,     0,
     -31,   -31,     0,   -31,   -31,     0,     0,   -31,     0,   -31,
     -31,   -32,     0,   -32,   -32,   -32,     0,   -32,     0,     0,
     -32,     0,     0,     0,     0,   -32,   -32,     0,   -32,   -32,
       0,     0,   -32,   -32,     0,   -32,   -32,     0,     0,   -32,
       0,   -32,   -32,   -34,     0,   -34,   -34,   -34,     0,   -34,
       0,     0,   -34,     0,     0,     0,     0,   -34,   -34,     0,
     -34,   -34,     0,     0,   -34,   -34,     0,   -34,   -34,     0,
       0,   -34,     0,   -34,   -34,   -41,     0,   -41,   -41,   -41,
       0,   -41,     0,     0,   -41,     0,     0,     0,     0,   -41,
     -41,     0,   -41,   -41,     0,     0,   -41,   -41,     0,   -41,
     -41,     0,     0,   -41,     0,   -41,   -41,   -42,     0,   -42,
     -42,   -42,     0,   -42,     0,     0,   -42,     0,     0,     0,
       0,   -42,   -42,     0,   -42,   -42,     0,     0,   -42,   -42,
       0,   -42,   -42,     0,     0,   -42,     0,   -42,   -42,   -43,
       0,   -43,   -43,   -43,     0,   -43,     0,     0,   -43,     0,
       0,     0,     0,   -43,   -43,     0,   -43,   -43,     0,     0,
     -43,   -43,     0,   -43,   -43,     0,     0,   -43,     0,   -43,
     -43,   -40,     0,   -40,   -40,   -40,     0,   -40,     0,     0,
     -40,     0,     0,     0,     0,   -40,   -40,     0,   -40,   -40,
       0,     0,   -40,   -40,     0,   -40,   -40,     0,     0,   -40,
       0,   -40,   -40,   -33,     0,   -33,   -33,   -33,     0,   -33,
       0,     0,   -33,     0,     0,     0,     0,   -33,   -33,     0,
     -33,   -33,     0,     0,   -33,   -33,     0,   -33,   -33,     0,
       0,   -33,     0,   -33,   -33,   -44,     0,   -44,   -44,   -44,
       0,   -44,     0,     0,   -44,     0,     0,     0,     0,   -44,
     -44,     0,   -44,   -44,     0,     0,   -44,   -44,     0,   -44,
     -44,     0,     0,   -44,     0,   -44,   -44,   -45,     0,   -45,
     -45,   -45,     0,   -45,     0,     0,   -45,     0,     0,     0,
       0,   -45,   -45,     0,   -45,   -45,     0,     0,   -45,   -45,
       0,   -45,   -45,     0,     0,   -45,     0,   -45,   -45,   -29,
       0,   -29,   -29,   -29,     0,   -29,     0,     0,   -29,     0,
       0,     0,     0,   -29,   -29,     0,   -29,   -29,     0,     0,
     -29,   -29,     0,   -29,   -29,     0,     0,   -29,     0,   -29,
     -29,   -37,     0,   -37,   -37,   -37,     0,   -37,     0,     0,
     -37,     0,     0,     0,     0,   -37,   -37,     0,   -37,   -37,
       0,     0,   -37,   -37,     0,   -37,   -37,     0,     0,   -37,
       0,   -37,   -37,   -30,     0,   -30,   -30,   -30,     0,   -30,
       0,     0,   -30,     0,     0,     0,     0,   -30,   -30,     0,
     -30,   -30,     0,     0,   -30,   -30,     0,   -30,   -30,     0,
       0,   -30,     0,   -30,   -30,   -13,     0,   -13,   -13,   -13,
       0,   -13,     0,     0,   -13,     0,     0,     0,     0,   -13,
     -13,     0,   -13,   -13,     0,     0,   -13,   -13,     0,   -13,
     -13,     0,     0,   -13,     0,   -13,   -13,   -49,     0,   -49,
     -49,   -49,     0,   -49,     0,     0,   -49,     0,     0,     0,
       0,   -49,   -49,     0,   -49,   -49,     0,     0,   -49,   -49,
       0,   -49,   -49,     0,     0,   -49,     0,   -49,   -49,   -47,
       0,   -47,   -47,   -47,     0,   -47,     0,     0,   -47,     0,
       0,     0,     0,   -47,   -47,     0,   -47,   -47,     0,     0,
     -47,   -47,     0,   -47,   -47,     0,     0,   -47,     0,   -47,
     -47,   -48,     0,   -48,   -48,   -48,     0,   -48,     0,     0,
     -48,     0,     0,     0,     0,   -48,   -48,     0,   -48,   -48,
       0,     0,   -48,   -48,     0,   -48,   -48,     0,     0,   -48,
       0,   -48,   -48,   -24,     0,   -24,   -24,   -24,     0,   -24,
       0,     0,   -24,     0,     0,     0,     0,   -24,   -24,     0,
     -24,   -24,     0,     0,   -24,   -24,     0,   -24,   -24,     0,
       0,   -24,     0,   -24,   -24,   -22,     0,   -22,   -22,   -22,
       0,   -22,     0,     0,   -22,     0,     0,     0,     0,   -22,
     -22,     0,   -22,   -22,     0,     0,   -22,   -22,     0,   -22,
     -22,     0,     0,   -22,     0,   -22,   -22,   -23,     0,   -23,
     -23,   -23,     0,   -23,     0,     0,   -23,     0,     0,     0,
       0,   -23,   -23,     0,   -23,   -23,     0,     0,   -23,   -23,
       0,   -23,   -23,     0,     0,   -23,     0,   -23,   -23,   -28,
       0,   -28,   -28,   -28,     0,   -28,     0,     0,   -28,     0,
       0,     0,     0,   -28,   -28,     0,   -28,   -28,     0,     0,
     -28,   -28,     0,   -28,   -28,     0,     0,   -28,     0,   -28,
     -28,   -21,     0,   -21,   -21,   -21,     0,   -21,     0,     0,
     -21,     0,     0,     0,     0,   -21,   -21,     0,   -21,   -21,
       0,     0,   -21,   -21,     0,   -21,   -21,     0,     0,   -21,
       0,   -21,   -21,   -27,     0,   -27,   -27,   -27,     0,   -27,
       0,     0,   -27,     0,     0,     0,     0,   -27,   -27,     0,
     -27,   -27,     0,     0,   -27,   -27,     0,   -27,   -27,     0,
       0,   -27,     0,   -27,   -27,    -9,     0,    -9,    -9,    -9,
       0,    -9,     0,     0,    -9,     0,     0,     0,     0,    -9,
      -9,     0,    -9,    -9,     0,     0,    -9,    -9,     0,    -9,
      -9,     0,     0,    -9,     0,    -9,    -9,   -12,     0,   -12,
     -12,   -12,     0,   -12,     0,     0,   -12,     0,     0,     0,
       0,   -12,   -12,     0,   -12,   -12,     0,     0,   -12,   -12,
      36,   -12,   -12,    38,    39,   -12,    40,   -12,   -12,    41,
       0,     0,     0,     0,    42,    43,     0,    44,    45,     0,
       0,    46,    47,   185,    48,    49,    38,    39,    50,    40,
     145,     0,    41,     0,     0,     0,     0,   186,   187,     0,
      44,    45,     0,     0,    46,   188,   185,   189,   190,    38,
      39,    50,    40,   270,     0,    41,     0,     0,     0,     0,
     186,   187,     0,    44,    45,     0,     0,    46,   188,   185,
     189,   190,    38,    39,    50,    40,   277,     0,    41,     0,
       0,     0,     0,   186,   187,     0,    44,    45,     0,     0,
      46,   188,   185,   189,   190,    38,    39,    50,    40,   283,
       0,    41,     0,     0,     0,     0,   186,   187,     0,    44,
      45,     0,     0,    46,   188,   151,   189,   190,   152,   153,
      50,   154,   286,     0,   155,     0,     0,     0,     0,     0,
       0,   151,   156,   157,   152,   153,   158,   154,     0,   255,
     155,     0,     0,   159,   -39,     0,     0,    84,   156,   157,
      38,    39,   158,    40,     0,     0,    41,     0,     0,   159,
       0,     0,     0,   168,    44,    45,   169,   170,    46,   171,
       0,     0,   172,     0,     0,    50,     0,     0,     0,     0,
     173,   174,    38,    39,   175,    40,     0,     0,    41,     0,
       0,   176,     0,     0,     0,     0,    44,    45,   152,   153,
      74,   154,     0,     0,   155,     0,     0,    50,     0,     0,
       0,     0,   156,   157,   169,   170,   199,   171,     0,     0,
     172,     0,     0,   159,   -66,   -66,   -66,   -66,   173,   174,
       0,   -66,   213,     0,   -66,   -66,     0,   -58,   207,   176,
       0,   217,   208,   218,   -66,   209,   210,     0,   -66,   -66,
     -66,   -66,   -66,     0,     0,   -58,   -66,     0,     0,   -66,
     -66,     0,     0,     0,   -68,   -68,   -68,   -68,   218,   -66,
       0,   -68,     0,   -66,   -68,   -68,   -70,   -70,   -70,   -70,
       0,     0,     0,   -70,   -68,     0,   -70,   -70,   -68,     0,
       0,   -62,   226,   -62,   -62,     0,   -70,     0,   -62,     0,
     -70,   -62,   -62,   -64,   -64,   -64,   -64,     0,     0,     0,
     -64,   -62,     0,   -64,   -64,   -62,     0,     0,   -71,   -71,
     -71,   -71,     0,   -64,     0,   -71,     0,   -64,   -71,   -71,
     -76,   -76,   -76,   -76,     0,     0,     0,   -76,   -71,     0,
     -76,   -76,   -71,     0,     0,   -78,   -78,   -78,   -78,     0,
     -76,     0,   -78,     0,   -76,   -78,   -78,   -77,   -77,   -77,
     -77,     0,     0,     0,   -77,   -78,     0,   -77,   -77,   -78,
       0,     0,   -65,   -65,   -65,   -65,     0,   -77,     0,   -65,
       0,   -77,   -65,   -65,   -61,   226,   -61,   -61,     0,     0,
       0,   -61,   -65,     0,   -61,   -61,   -65,     0,     0,   -63,
     -63,   -63,   -63,     0,   -61,     0,   -63,     0,   -61,   -63,
     -63,   -69,   -69,   -69,   -69,     0,     0,     0,   -69,   -63,
       0,   -69,   -69,   -63,     0,     0,   -66,   -66,   -66,   -66,
       0,   -69,     0,   -66,     0,   -69,   -66,   -66,     0,     0,
       0,     0,     0,    80,     0,    81,     0,     0,     0,   -66,
     -67,   -67,   -67,   -67,     0,     0,     0,   -67,     0,     0,
     -67,   -67,     0,     0,   -68,   -68,   -68,   -68,     0,     0,
       0,   -68,     0,   -67,   -68,   -68,     0,     0,   -70,   -70,
     -70,   -70,     0,     0,     0,   -70,     0,   -68,   -70,   -70,
       0,     0,   -62,    96,   -62,   -62,     0,     0,     0,   -62,
       0,   -70,   -62,   -62,     0,     0,   -64,   -64,   -64,   -64,
       0,     0,     0,   -64,     0,   -62,   -64,   -64,     0,     0,
     -71,   -71,   -71,   -71,     0,     0,     0,   -71,     0,   -64,
     -71,   -71,     0,     0,   -76,   -76,   -76,   -76,     0,     0,
       0,   -76,     0,   -71,   -76,   -76,     0,     0,   -78,   -78,
     -78,   -78,     0,     0,     0,   -78,     0,   -76,   -78,   -78,
       0,     0,   -77,   -77,   -77,   -77,     0,     0,     0,   -77,
       0,   -78,   -77,   -77,     0,     0,   -65,   -65,   -65,   -65,
       0,     0,     0,   -65,     0,   -77,   -65,   -65,     0,     0,
     -61,    96,   -61,   -61,     0,     0,     0,   -61,     0,   -65,
     -61,   -61,     0,     0,   -63,   -63,   -63,   -63,     0,     0,
       0,   -63,     0,   -61,   -63,   -63,     0,     0,   -69,   -69,
     -69,   -69,     0,     0,     0,   -69,     0,   -63,   -69,   -69,
       0,     0,    95,     0,   -60,   -60,     0,     0,     0,   -60,
       0,   -69,   -60,   -60,     0,     0,    95,     0,   -59,   -59,
       0,     0,     0,   -59,     0,   -60,   -59,   -59,     0,     0,
     -66,   -66,   -66,   -66,     0,     0,     0,   -66,     0,   -59,
     -66,   -66,     0,     0,   -67,   -67,   -67,   -67,     0,   204,
     -66,   -67,     0,     0,   -67,   -67,   -68,   -68,   -68,   -68,
       0,     0,     0,   -68,   -67,     0,   -68,   -68,   -70,   -70,
     -70,   -70,     0,     0,     0,   -70,   -68,     0,   -70,   -70,
     -62,   212,   -62,   -62,     0,     0,     0,   -62,   -70,     0,
     -62,   -62,   -64,   -64,   -64,   -64,     0,     0,     0,   -64,
     -62,     0,   -64,   -64,   -71,   -71,   -71,   -71,     0,     0,
       0,   -71,   -64,     0,   -71,   -71,   -76,   -76,   -76,   -76,
       0,     0,     0,   -76,   -71,     0,   -76,   -76,   -78,   -78,
     -78,   -78,     0,     0,     0,   -78,   -76,     0,   -78,   -78,
     -77,   -77,   -77,   -77,     0,     0,     0,   -77,   -78,     0,
     -77,   -77,   -65,   -65,   -65,   -65,     0,     0,     0,   -65,
     -77,     0,   -65,   -65,   -61,   212,   -61,   -61,     0,     0,
       0,   -61,   -65,     0,   -61,   -61,   -63,   -63,   -63,   -63,
       0,     0,     0,   -63,   -61,     0,   -63,   -63,   -69,   -69,
     -69,   -69,     0,     0,     0,   -69,   -63,     0,   -69,   -69,
     211,     0,   -60,   -60,     0,     0,     0,   -60,   -69,     0,
     -60,   -60,   211,     0,   -59,   -59,     0,     0,     0,   -59,
     -60,     0,   -59,   -59,     0,     0,     0,     0,     0,     0,
       0,     0,   -59
};

static const yytype_int16 yycheck[] =
{
      32,     6,   124,     1,    12,     3,   123,    50,    12,   204,
      12,    33,   134,     0,    33,    33,   133,    22,    33,    51,
      12,    12,   139,   218,   141,    33,    12,    49,    50,    33,
      33,    33,    30,    10,    77,    12,    13,    22,    81,    82,
      17,    33,    33,    20,    21,     1,    30,    33,     4,     5,
      33,     7,    30,    30,    10,    77,    34,    34,    80,    81,
      82,    83,    18,    19,    33,    10,    22,    12,    13,    12,
      12,    30,    17,    29,    30,    20,    21,     1,    34,   122,
       4,     5,     1,     7,     3,    30,    10,    30,    30,    34,
       6,   134,    34,    22,    18,    19,    31,   129,    22,    29,
     122,     3,   124,    33,   136,    29,    22,    12,   230,    33,
     142,   133,   134,   145,   133,   133,   159,   139,   133,   141,
     139,   139,   141,   141,   139,    30,   141,    12,    29,    34,
     133,    30,    33,   176,    31,    34,   139,   159,   141,     6,
      32,    12,    32,    41,   266,    30,    44,    45,   265,    34,
     133,    12,    50,   275,   176,    22,   139,   274,   141,    30,
     203,   204,    12,   280,   133,   282,    29,    29,   190,    30,
     139,    12,   141,    34,   217,   218,    12,    29,    29,    77,
      30,   203,   204,    81,    82,   228,   229,    12,    33,    30,
      10,    11,    12,    13,    30,   217,   218,    17,    96,    12,
      20,    21,    33,    22,    22,    30,   228,   229,   230,     1,
      30,    12,     4,     5,    34,     7,    30,    30,    10,    30,
      34,    34,    32,    34,   122,    33,    18,    19,    33,    30,
      22,    30,   275,    34,    12,    13,   134,    29,   270,    17,
      33,    33,    20,    21,   266,   277,    30,    30,    30,    30,
      34,   283,    30,   275,   286,    30,    34,   155,   156,   157,
      50,   159,     1,    30,    33,     4,     5,    34,     7,    30,
      33,    10,    32,    34,   172,   173,   174,    30,   176,    18,
      19,    34,    30,    22,    30,    30,    34,    77,    34,    34,
      29,    81,    82,    30,    33,    30,    32,    34,    30,    34,
       0,     1,    34,     3,    33,   203,   204,    33,   206,   207,
     208,   209,   210,   211,   212,    33,    50,    33,    33,   217,
     218,    30,   220,   221,   222,   223,   224,   225,   226,    32,
     228,   229,   122,    32,     0,     1,     1,     3,    30,     4,
       5,    29,     7,    77,   134,    10,    29,    81,    82,    10,
      11,    12,    13,    18,    19,    29,    17,    22,    29,    20,
      21,    95,    30,    33,    29,   155,   156,   157,    29,   159,
       0,     1,    33,     3,    30,     0,     1,   275,     3,    30,
      22,    33,   172,   173,   174,    30,   176,     1,   122,    30,
       4,     5,    30,     7,    30,     9,    10,    30,     0,     1,
     134,     3,    12,    13,    18,    19,    33,    17,    22,    33,
      20,    21,    33,   203,   204,    29,   206,   207,   208,   209,
     210,   211,   212,    33,    50,   159,    33,   217,   218,    33,
     220,   221,   222,   223,   224,   225,   226,    32,   228,   229,
      30,    32,   176,    10,    11,    12,    13,    32,    32,     4,
      17,    77,    33,    20,    21,    81,    82,    33,     0,     1,
      27,     3,    29,    30,    90,    16,    92,    93,    94,   203,
     204,    27,   206,   207,   208,   209,   210,   211,     0,     1,
      50,     3,    -1,   217,   218,   275,   220,   221,   222,   223,
     224,   225,    -1,    -1,   228,   229,   122,     0,     1,    -1,
       3,     0,     1,    -1,     3,    -1,    -1,    77,   134,    -1,
       1,    81,    82,     4,     5,    50,     7,     0,     1,    10,
       3,    91,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,   159,    25,    26,     0,     1,    29,     3,
      31,   275,    77,    -1,    -1,     1,    81,    82,     4,     5,
     176,     7,   122,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,   134,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    31,    -1,   203,   204,    -1,
     206,    -1,   208,   209,   210,    -1,    -1,   122,    -1,   159,
      -1,   217,   218,    -1,   220,    -1,   222,   223,   224,   134,
      -1,     1,   228,   229,     4,     5,   176,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,   159,    25,    26,    -1,    -1,    29,
      -1,    31,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   176,    -1,    -1,    -1,    -1,    -1,   217,   218,   275,
     220,   221,   222,   223,   224,    -1,    -1,    -1,   228,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,   204,
      -1,   206,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,    -1,   220,    -1,   222,   223,   224,
      -1,    -1,    -1,   228,   229,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,   275,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,    33,     1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
     275,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,    31,    32,
      33,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    -1,    -1,    29,    -1,    31,    32,     1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    -1,    -1,    29,    -1,    31,
      32,     1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      -1,    31,    32,     1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      -1,    29,    -1,    31,    32,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    31,    32,     1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
       1,    25,    26,     4,     5,    29,     7,    31,    32,    10,
      -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,     1,    25,    26,     4,     5,    29,     7,
      31,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,     1,    25,    26,     4,
       5,    29,     7,    31,    -1,    10,    -1,    -1,    -1,    -1,
      15,    16,    -1,    18,    19,    -1,    -1,    22,    23,     1,
      25,    26,     4,     5,    29,     7,    31,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,     1,    25,    26,     4,     5,    29,     7,    31,
      -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,     1,    25,    26,     4,     5,
      29,     7,    31,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    18,    19,     4,     5,    22,     7,    -1,     9,
      10,    -1,    -1,    29,    30,    -1,    -1,     1,    18,    19,
       4,     5,    22,     7,    -1,    -1,    10,    -1,    -1,    29,
      -1,    -1,    -1,     1,    18,    19,     4,     5,    22,     7,
      -1,    -1,    10,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      18,    19,     4,     5,    22,     7,    -1,    -1,    10,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    18,    19,     4,     5,
      22,     7,    -1,    -1,    10,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    18,    19,     4,     5,    22,     7,    -1,    -1,
      10,    -1,    -1,    29,    10,    11,    12,    13,    18,    19,
      -1,    17,    22,    -1,    20,    21,    -1,    12,    13,    29,
      -1,    27,    17,    29,    30,    20,    21,    -1,    34,    10,
      11,    12,    13,    -1,    -1,    30,    17,    -1,    -1,    20,
      21,    -1,    -1,    -1,    10,    11,    12,    13,    29,    30,
      -1,    17,    -1,    34,    20,    21,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    30,    -1,    20,    21,    34,    -1,
      -1,    10,    11,    12,    13,    -1,    30,    -1,    17,    -1,
      34,    20,    21,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    30,    -1,    20,    21,    34,    -1,    -1,    10,    11,
      12,    13,    -1,    30,    -1,    17,    -1,    34,    20,    21,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    30,    -1,
      20,    21,    34,    -1,    -1,    10,    11,    12,    13,    -1,
      30,    -1,    17,    -1,    34,    20,    21,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,    34,
      -1,    -1,    10,    11,    12,    13,    -1,    30,    -1,    17,
      -1,    34,    20,    21,    10,    11,    12,    13,    -1,    -1,
      -1,    17,    30,    -1,    20,    21,    34,    -1,    -1,    10,
      11,    12,    13,    -1,    30,    -1,    17,    -1,    34,    20,
      21,    10,    11,    12,    13,    -1,    -1,    -1,    17,    30,
      -1,    20,    21,    34,    -1,    -1,    10,    11,    12,    13,
      -1,    30,    -1,    17,    -1,    34,    20,    21,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    -1,    -1,    -1,    33,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    -1,    -1,    10,    11,    12,    13,    -1,    -1,
      -1,    17,    -1,    33,    20,    21,    -1,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    -1,    33,    20,    21,
      -1,    -1,    10,    11,    12,    13,    -1,    -1,    -1,    17,
      -1,    33,    20,    21,    -1,    -1,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    -1,    33,    20,    21,    -1,    -1,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,    33,
      20,    21,    -1,    -1,    10,    11,    12,    13,    -1,    -1,
      -1,    17,    -1,    33,    20,    21,    -1,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    -1,    33,    20,    21,
      -1,    -1,    10,    11,    12,    13,    -1,    -1,    -1,    17,
      -1,    33,    20,    21,    -1,    -1,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    -1,    33,    20,    21,    -1,    -1,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,    33,
      20,    21,    -1,    -1,    10,    11,    12,    13,    -1,    -1,
      -1,    17,    -1,    33,    20,    21,    -1,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    -1,    33,    20,    21,
      -1,    -1,    10,    -1,    12,    13,    -1,    -1,    -1,    17,
      -1,    33,    20,    21,    -1,    -1,    10,    -1,    12,    13,
      -1,    -1,    -1,    17,    -1,    33,    20,    21,    -1,    -1,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,    33,
      20,    21,    -1,    -1,    10,    11,    12,    13,    -1,    29,
      30,    17,    -1,    -1,    20,    21,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    30,    -1,    20,    21,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    30,    -1,
      20,    21,    10,    11,    12,    13,    -1,    -1,    -1,    17,
      30,    -1,    20,    21,    10,    11,    12,    13,    -1,    -1,
      -1,    17,    30,    -1,    20,    21,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    30,    -1,    20,    21,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    30,    -1,
      20,    21,    10,    11,    12,    13,    -1,    -1,    -1,    17,
      30,    -1,    20,    21,    10,    11,    12,    13,    -1,    -1,
      -1,    17,    30,    -1,    20,    21,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    30,    -1,    20,    21,    10,    11,
      12,    13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,
      10,    -1,    12,    13,    -1,    -1,    -1,    17,    30,    -1,
      20,    21,    10,    -1,    12,    13,    -1,    -1,    -1,    17,
      30,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    36,    37,    38,    39,    40,    41,     6,
      22,     0,    38,    22,    29,    33,    29,    33,     1,     3,
      43,    44,    45,    43,     6,    22,    30,    34,    30,    22,
      31,    45,    31,    49,    50,    50,     1,     3,     4,     5,
       7,    10,    15,    16,    18,    19,    22,    23,    25,    26,
      29,    31,    39,    41,    42,    46,    47,    48,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    65,
      32,    32,     6,    22,    22,    62,    29,    29,    62,    62,
      27,    29,    29,    29,     1,    33,    56,    56,    50,    33,
      12,    13,    17,    20,    21,    10,    11,    22,    22,     9,
      56,    56,    56,    63,    64,    56,    52,    56,    33,    30,
      32,    58,    60,    58,    58,    58,    61,    62,    30,    30,
      30,    30,    34,    30,    33,    33,    33,    33,    56,    31,
      53,    52,    50,    24,    33,    32,    31,    53,    52,    24,
      50,    30,    31,    53,    32,    31,    53,    50,    50,    32,
      32,     1,     4,     5,     7,    10,    18,    19,    22,    29,
      57,    58,    59,    60,    61,    62,    65,    33,     1,     4,
       5,     7,    10,    18,    19,    22,    29,    57,    58,    59,
      60,    61,    62,    65,    33,     1,    15,    16,    23,    25,
      26,    46,    47,    48,    51,    54,    55,    56,    56,    22,
      62,    62,    62,    27,    29,    56,    12,    13,    17,    20,
      21,    10,    11,    22,    62,    62,    62,    27,    29,    56,
      12,    13,    17,    20,    21,    10,    11,    29,    29,    29,
      29,    33,    56,    33,    56,    64,    30,    58,    60,    58,
      58,    58,    61,    62,    56,    64,    30,    58,    60,    58,
      58,    58,    61,    62,    22,     9,    56,    56,    52,    33,
      30,    30,    30,    30,    30,    30,    33,    33,    33,    33,
      31,    53,    52,    50,    24,    33,    32,    31,    53,    52,
      24,    50,    30,    31,    53,    32,    31,    53,    50,    50,
      32,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    39,
      40,    40,    41,    42,    43,    43,    44,    44,    44,    45,
      45,    46,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    50,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       8,     9,     4,     3,     1,     0,     3,     1,     1,     2,
       3,    11,     9,     9,     7,     7,     5,    11,     9,     2,
       3,     2,     2,     2,     2,     0,     1,     2,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       3,     1,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     4,
       1,     1,     3,     1,     1,     0,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 118 "src/sintatico.y"
                     { 
        (yyval.node) = create_node("program");
        (yyval.node)->node1 = (yyvsp[0].node);
        root = (yyval.node);
    }
#line 2198 "src/sintatico.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 126 "src/sintatico.y"
                                 {
        (yyval.node) = create_node("declaration_list");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2208 "src/sintatico.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 131 "src/sintatico.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2216 "src/sintatico.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 138 "src/sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2222 "src/sintatico.tab.c"
    break;

  case 6: /* declaration: function_declaration  */
#line 139 "src/sintatico.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2228 "src/sintatico.tab.c"
    break;

  case 7: /* declaration: list_declaration  */
#line 140 "src/sintatico.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2234 "src/sintatico.tab.c"
    break;

  case 8: /* declaration: error  */
#line 141 "src/sintatico.y"
            {yyerrok;}
#line 2240 "src/sintatico.tab.c"
    break;

  case 9: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 145 "src/sintatico.y"
                       {
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-1].token).body, get_stack_top(&scope_stack), (yyvsp[-1].token).line, (yyvsp[-1].token).columns);
        if(create == 0){
            symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, (yyvsp[-2].token).body, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        (yyval.node) = create_node("var_declaration");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-2].token).line;
        (yyval.node)->column = (yyvsp[-2].token).columns;
        (yyval.node)->node2->line = (yyvsp[-1].token).line;
        (yyval.node)->node2->column = (yyvsp[-1].token).columns;
        (yyval.node)->node2->var_scope = get_stack_top(&scope_stack); 

        strcpy((yyval.node)->node2->type, (yyvsp[-2].token).body);
        assign_types((yyval.node)->node2, symbol_table, &scope_stack); 
    }
#line 2267 "src/sintatico.tab.c"
    break;

  case 10: /* function_declaration: SIMPLE_TYPE ID '(' params_list ')' '{' multiple_stmt '}'  */
#line 170 "src/sintatico.y"
                                                             {
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-6].token).body, get_stack_top(&scope_stack), (yyvsp[-6].token).line, (yyvsp[-6].token).columns);
        if(create == 0){
            symbol new_symbol = add_symbol((yyvsp[-6].token).line, (yyvsp[-6].token).columns, (yyvsp[-6].token).body, (yyvsp[-7].token).body, 1, get_stack_top(&scope_stack));
            // printf("Current function: (%s) %s\n", $1.body, $2.body);
            new_symbol.function_params = param_counter;
            new_symbol.param = param;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;   
            param_counter = 0;
            // empty_params(param

        }
        (yyval.node) = create_node("function_declaration");
        (yyval.node)->node1 = create_node((yyvsp[-7].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node2->is_function = 1;
        (yyval.node)->node2->line = (yyvsp[-6].token).line;
        (yyval.node)->node2->column = (yyvsp[-6].token).columns;
        (yyval.node)->node2->var_scope = get_stack_top(&scope_stack);
        strcpy((yyval.node)->node2->type, (yyvsp[-7].token).body);
        assign_types((yyval.node)->node2, symbol_table, &scope_stack);
        if(errors == 0){
            search_return((yyval.node), "return", (yyval.node)->node2->type); 
        }
    }
#line 2303 "src/sintatico.tab.c"
    break;

  case 11: /* function_declaration: SIMPLE_TYPE LIST_TYPE ID '(' params_list ')' '{' multiple_stmt '}'  */
#line 201 "src/sintatico.y"
                                                                         {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-6].token).body, get_stack_top(&scope_stack), (yyvsp[-6].token).line, (yyvsp[-6].token).columns);
        if(create == 0){   
            strcpy(str_simple_type, (yyvsp[-8].token).body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, (yyvsp[-7].token).body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol((yyvsp[-6].token).line, (yyvsp[-6].token).columns, (yyvsp[-6].token).body, list_string, 1, get_stack_top(&scope_stack));
            // printf("Current function: (%s) %s\n", list_string, $3.body);
            new_symbol.function_params = param_counter;
            new_symbol.param = param;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
            param_counter = 0;
        }
        
        (yyval.node) = create_node("function_declaration");
        (yyval.node)->node1 = create_node(list_string);
        (yyval.node)->node2 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node2->is_function = 1;
        (yyval.node)->node2->line = (yyvsp[-6].token).line;
        (yyval.node)->node2->column = (yyvsp[-6].token).columns;
        (yyval.node)->node2->var_scope = get_stack_top(&scope_stack);

        strcpy((yyval.node)->node2->type, list_string);
        assign_types((yyval.node)->node2, symbol_table, &scope_stack);
        if(errors == 0){
            search_return((yyval.node), "return", list_string);
        }

    }
#line 2347 "src/sintatico.tab.c"
    break;

  case 12: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID ';'  */
#line 243 "src/sintatico.y"
                                 {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-1].token).body, get_stack_top(&scope_stack), (yyvsp[-1].token).line, (yyvsp[-1].token).columns);
        if(create == 0){   
            strcpy(str_simple_type, (yyvsp[-3].token).body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, (yyvsp[-2].token).body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, list_string, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        (yyval.node) = create_node("list_declaration");
        (yyval.node)->node1 = create_node(list_string);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node2->line = (yyvsp[-1].token).line;
        (yyval.node)->node2->column = (yyvsp[-1].token).columns;
        (yyval.node)->node2->var_scope = get_stack_top(&scope_stack);
        
        strcpy((yyval.node)->node2->type, list_string);
        assign_types((yyval.node)->node2, symbol_table ,&scope_stack);
    }
#line 2380 "src/sintatico.tab.c"
    break;

  case 13: /* scope_declaration: '{' multiple_stmt '}'  */
#line 274 "src/sintatico.y"
                          {
        (yyval.node) = create_node("scope_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2390 "src/sintatico.tab.c"
    break;

  case 14: /* params_list: params  */
#line 282 "src/sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2396 "src/sintatico.tab.c"
    break;

  case 15: /* params_list: %empty  */
#line 283 "src/sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2404 "src/sintatico.tab.c"
    break;

  case 16: /* params: params ',' param  */
#line 289 "src/sintatico.y"
                     {
        (yyval.node) = create_node("params");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = (yyvsp[0].node);

    }
#line 2415 "src/sintatico.tab.c"
    break;

  case 17: /* params: param  */
#line 295 "src/sintatico.y"
            {
        (yyval.node) = create_node("params");
        (yyval.node)->node1 = (yyvsp[0].node);
    }
#line 2424 "src/sintatico.tab.c"
    break;

  case 18: /* params: error  */
#line 299 "src/sintatico.y"
            {yyerrok;}
#line 2430 "src/sintatico.tab.c"
    break;

  case 19: /* param: SIMPLE_TYPE ID  */
#line 303 "src/sintatico.y"
                   {
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, (yyvsp[0].token).body, get_stack_top(&scope_stack), (yyvsp[0].token).line, (yyvsp[0].token).columns);
        if(create == 0){    
            strcpy(param[param_counter].argument_type, (yyvsp[-1].token).body);
            param_counter++;
            // printf(BCYAN"%s "RESET BMAG"%s\n"RESET, $1.body, $2.body);
            symbol new_symbol = add_symbol((yyvsp[0].token).line, (yyvsp[0].token).columns, (yyvsp[0].token).body, (yyvsp[-1].token).body, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        (yyval.node) = create_node("param");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = create_node((yyvsp[0].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node2->line = (yyvsp[0].token).line;
        (yyval.node)->node2->column = (yyvsp[0].token).columns;
        strcpy((yyval.node)->node2->type, (yyvsp[-1].token).body);
        assign_types((yyval.node)->node2, symbol_table, &scope_stack);
        (yyval.node)->node2->var_scope = get_stack_top(&scope_stack);
        pop(&scope_stack);
        scope--;
    }
#line 2461 "src/sintatico.tab.c"
    break;

  case 20: /* param: SIMPLE_TYPE LIST_TYPE ID  */
#line 329 "src/sintatico.y"
                               {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, (yyvsp[0].token).body, get_stack_top(&scope_stack), (yyvsp[0].token).line, (yyvsp[0].token).columns);
        if(create == 0){
            // Concatenating SIMPLE_TYPE + LIST_TYPE
            strcpy(str_simple_type, (yyvsp[-2].token).body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, (yyvsp[-1].token).body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            // End of concatenation
            strcpy(param[param_counter].argument_type, list_string);
            param_counter++;
            // printf(BCYAN"%s "RESET BMAG"%s\n"RESET, list_string, $3.body);
            symbol new_symbol = add_symbol((yyvsp[0].token).line, (yyvsp[0].token).columns, (yyvsp[0].token).body, list_string, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        (yyval.node) = create_node("param");
        (yyval.node)->node1 = create_node(list_string);
        (yyval.node)->node2 = create_node((yyvsp[0].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node2->line = (yyvsp[0].token).line;
        (yyval.node)->node2->column = (yyvsp[0].token).columns;
        (yyval.node)->node2->var_scope = get_stack_top(&scope_stack);
        strcpy((yyval.node)->node2->type, list_string);
        assign_types((yyval.node)->node2, symbol_table, &scope_stack);
        pop(&scope_stack);
        scope--;
    }
#line 2502 "src/sintatico.tab.c"
    break;

  case 21: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}'  */
#line 368 "src/sintatico.y"
                                                                           {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-5].node);
        (yyval.node)->node4 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node5 = (yyvsp[-1].node);
        (yyval.node)->line = (yyvsp[-10].token).line;
        (yyval.node)->column = (yyvsp[-10].token).columns;
    }
#line 2517 "src/sintatico.tab.c"
    break;

  case 22: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt  */
#line 378 "src/sintatico.y"
                                                            {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-3].node);
        (yyval.node)->node4 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node5 = (yyvsp[0].node);
        (yyval.node)->line = (yyvsp[-8].token).line;
        (yyval.node)->column = (yyvsp[-8].token).columns;
    }
#line 2532 "src/sintatico.tab.c"
    break;

  case 23: /* if_else_stmt: IF '(' expression ')' stmt ELSE '{' multiple_stmt '}'  */
#line 388 "src/sintatico.y"
                                                            {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node5 = (yyvsp[-1].node);
        (yyval.node)->line = (yyvsp[-8].token).line;
        (yyval.node)->column = (yyvsp[-8].token).columns;
    }
#line 2547 "src/sintatico.tab.c"
    break;

  case 24: /* if_else_stmt: IF '(' expression ')' stmt ELSE stmt  */
#line 398 "src/sintatico.y"
                                           { 
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node2 = (yyvsp[-4].node);
        (yyval.node)->node3 = (yyvsp[-2].node);
        (yyval.node)->node4 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node5 = (yyvsp[0].node);
        (yyval.node)->line = (yyvsp[-6].token).line;
        (yyval.node)->column = (yyvsp[-6].token).columns;
    }
#line 2562 "src/sintatico.tab.c"
    break;

  case 25: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}'  */
#line 408 "src/sintatico.y"
                                                  {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node2 = (yyvsp[-4].node);
        (yyval.node)->node3 = (yyvsp[-1].node);
        (yyval.node)->line = (yyvsp[-6].token).line;
        (yyval.node)->column = (yyvsp[-6].token).columns;
    }
#line 2575 "src/sintatico.tab.c"
    break;

  case 26: /* if_else_stmt: IF '(' expression ')' stmt  */
#line 416 "src/sintatico.y"
                                 {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = (yyvsp[-2].node);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->line = (yyvsp[-4].token).line;
        (yyval.node)->column = (yyvsp[-4].token).columns;    
    }
#line 2588 "src/sintatico.tab.c"
    break;

  case 27: /* for_stmt: FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' '{' multiple_stmt '}'  */
#line 427 "src/sintatico.y"
                                                                                                                                           {
        (yyval.node) = create_node("for_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-6].node);
        (yyval.node)->node4 = (yyvsp[-4].node);
        (yyval.node)->node5 = (yyvsp[-1].node);
        (yyval.node)->line = (yyvsp[-10].token).line;
        (yyval.node)->column = (yyvsp[-10].token).columns;
    }
#line 2603 "src/sintatico.tab.c"
    break;

  case 28: /* for_stmt: FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' stmt  */
#line 437 "src/sintatico.y"
                                                                                                                            {
        (yyval.node) = create_node("for_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-2].node);
        (yyval.node)->node5 = (yyvsp[0].node);
        (yyval.node)->line = (yyvsp[-8].token).line;
        (yyval.node)->column = (yyvsp[-8].token).columns;
    }
#line 2618 "src/sintatico.tab.c"
    break;

  case 29: /* return_stmt: RETURN ';'  */
#line 450 "src/sintatico.y"
               {(yyval.node) = create_node((yyvsp[-1].token).body);}
#line 2624 "src/sintatico.tab.c"
    break;

  case 30: /* return_stmt: RETURN expression ';'  */
#line 451 "src/sintatico.y"
                            {
        (yyval.node) = create_node((yyvsp[-2].token).body);
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->line = (yyvsp[-2].token).line;
        (yyval.node)->column = (yyvsp[-2].token).columns;

    }
#line 2636 "src/sintatico.tab.c"
    break;

  case 31: /* general_declaration: general_declaration var_declaration  */
#line 461 "src/sintatico.y"
                                        {
        (yyval.node) = create_node("general_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2646 "src/sintatico.tab.c"
    break;

  case 32: /* general_declaration: general_declaration list_declaration  */
#line 466 "src/sintatico.y"
                                           {
        (yyval.node) = create_node("general_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2656 "src/sintatico.tab.c"
    break;

  case 33: /* general_declaration: general_declaration stmt  */
#line 471 "src/sintatico.y"
                               {
        (yyval.node) = create_node("general_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2666 "src/sintatico.tab.c"
    break;

  case 34: /* general_declaration: general_declaration scope_declaration  */
#line 476 "src/sintatico.y"
                                           {
        (yyval.node) = create_node("general_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2676 "src/sintatico.tab.c"
    break;

  case 35: /* general_declaration: %empty  */
#line 481 "src/sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2684 "src/sintatico.tab.c"
    break;

  case 36: /* multiple_stmt: general_declaration  */
#line 487 "src/sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2690 "src/sintatico.tab.c"
    break;

  case 37: /* expression_stmt: expression ';'  */
#line 491 "src/sintatico.y"
                   {(yyval.node) = (yyvsp[-1].node);}
#line 2696 "src/sintatico.tab.c"
    break;

  case 38: /* for_variation_null_expressions: expression  */
#line 495 "src/sintatico.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2702 "src/sintatico.tab.c"
    break;

  case 39: /* for_variation_null_expressions: %empty  */
#line 496 "src/sintatico.y"
             {(yyval.node) = create_node("empty");}
#line 2708 "src/sintatico.tab.c"
    break;

  case 40: /* stmt: expression_stmt  */
#line 500 "src/sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2714 "src/sintatico.tab.c"
    break;

  case 41: /* stmt: if_else_stmt  */
#line 501 "src/sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2720 "src/sintatico.tab.c"
    break;

  case 42: /* stmt: for_stmt  */
#line 502 "src/sintatico.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2726 "src/sintatico.tab.c"
    break;

  case 43: /* stmt: return_stmt  */
#line 503 "src/sintatico.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2732 "src/sintatico.tab.c"
    break;

  case 44: /* stmt: print  */
#line 504 "src/sintatico.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2738 "src/sintatico.tab.c"
    break;

  case 45: /* stmt: scan  */
#line 505 "src/sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2744 "src/sintatico.tab.c"
    break;

  case 46: /* stmt: error  */
#line 506 "src/sintatico.y"
            {yyerrok;}
#line 2750 "src/sintatico.tab.c"
    break;

  case 47: /* print: OUTPUT '(' STRING ')' ';'  */
#line 511 "src/sintatico.y"
                              {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
        (yyval.node)->line = (yyvsp[-4].token).line;
        (yyval.node)->column = (yyvsp[-4].token).columns;
    }
#line 2762 "src/sintatico.tab.c"
    break;

  case 48: /* print: OUTPUT '(' expression ')' ';'  */
#line 518 "src/sintatico.y"
                                    {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = (yyvsp[-2].node);
        (yyval.node)->line = (yyvsp[-4].token).line;
        (yyval.node)->column = (yyvsp[-4].token).columns;
        evaluate_read_write((yyval.node), (yyval.node)->node2);
    }
#line 2775 "src/sintatico.tab.c"
    break;

  case 49: /* scan: INPUT '(' ID ')' ';'  */
#line 529 "src/sintatico.y"
                         {
        (yyval.node) = create_node("scan");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
        (yyval.node)->line = (yyvsp[-4].token).line;
        (yyval.node)->column = (yyvsp[-4].token).columns;
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node2->line = (yyvsp[-2].token).line;
        (yyval.node)->node2->column = (yyvsp[-2].token).columns;
        (yyval.node)->node2->var_scope = get_stack_top(&scope_stack);
        assign_types((yyval.node)->node2, symbol_table, &scope_stack);
        search_undeclared_node((yyval.node)->node2, symbol_table, &scope_stack);
        evaluate_read_write((yyval.node), (yyval.node)->node2);
    }
#line 2794 "src/sintatico.tab.c"
    break;

  case 50: /* expression: ID '=' expression  */
#line 546 "src/sintatico.y"
                      {
        (yyval.node) = create_node("expression");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node1->line = (yyvsp[-2].token).line;
        (yyval.node)->node1->column = (yyvsp[-2].token).columns;
        (yyval.node)->node1->var_scope = get_stack_top(&scope_stack);
        search_undeclared_node((yyval.node)->node1, symbol_table, &scope_stack);
        assign_types((yyval.node)->node1, symbol_table, &scope_stack);
        evaluate_assignment((yyval.node)->node1, (yyval.node), (yyval.node)->node3);

    }
#line 2813 "src/sintatico.tab.c"
    break;

  case 51: /* expression: simple_expression  */
#line 560 "src/sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2819 "src/sintatico.tab.c"
    break;

  case 52: /* expression: error  */
#line 561 "src/sintatico.y"
            {yyerrok;}
#line 2825 "src/sintatico.tab.c"
    break;

  case 53: /* simple_expression: list_operation  */
#line 566 "src/sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2831 "src/sintatico.tab.c"
    break;

  case 54: /* simple_expression: simple_expression LOGIC_OP list_operation  */
#line 567 "src/sintatico.y"
                                                {
        (yyval.node) = create_node("simple_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;
        
        evaluate_logical((yyval.node)->node1, (yyval.node), (yyval.node)->node3);
    }
#line 2847 "src/sintatico.tab.c"
    break;

  case 55: /* list_operation: relational_expression MAP list_operation  */
#line 582 "src/sintatico.y"
                                             {
        (yyval.node) = create_node("list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_list_exp((yyval.node)->node1, (yyval.node), (yyval.node)->node3, (yyval.node)->node2);
    }
#line 2863 "src/sintatico.tab.c"
    break;

  case 56: /* list_operation: relational_expression FILTER list_operation  */
#line 593 "src/sintatico.y"
                                                  {
        (yyval.node) = create_node("list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_list_exp((yyval.node)->node1, (yyval.node), (yyval.node)->node3, (yyval.node)->node2);
    }
#line 2879 "src/sintatico.tab.c"
    break;

  case 57: /* list_operation: relational_expression BINARY_CONSTRUCTOR list_operation  */
#line 604 "src/sintatico.y"
                                                              {
        (yyval.node) = create_node("list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_list_exp((yyval.node)->node1, (yyval.node), (yyval.node)->node3, (yyval.node)->node2);
    }
#line 2895 "src/sintatico.tab.c"
    break;

  case 58: /* list_operation: relational_expression  */
#line 615 "src/sintatico.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2901 "src/sintatico.tab.c"
    break;

  case 59: /* relational_expression: relational_expression BINARY_COMP_OP arithmetic_expression  */
#line 620 "src/sintatico.y"
                                                               {
        (yyval.node) = create_node("relational_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;
        evaluate_relational((yyval.node)->node1, (yyval.node), (yyval.node)->node3);
    }
#line 2916 "src/sintatico.tab.c"
    break;

  case 60: /* relational_expression: arithmetic_expression  */
#line 630 "src/sintatico.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2922 "src/sintatico.tab.c"
    break;

  case 61: /* arithmetic_expression: arithmetic_expression BINARY_BASIC_OP1 term  */
#line 634 "src/sintatico.y"
                                                {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_arithmetic((yyval.node)->node1, (yyval.node), (yyval.node)->node3);
    }
#line 2938 "src/sintatico.tab.c"
    break;

  case 62: /* arithmetic_expression: term  */
#line 645 "src/sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2944 "src/sintatico.tab.c"
    break;

  case 63: /* term: term BINARY_BASIC_OP2 factor  */
#line 649 "src/sintatico.y"
                                 {
        (yyval.node) = create_node("term");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_mult_div((yyval.node)->node1, (yyval.node), (yyval.node)->node3);
    }
#line 2960 "src/sintatico.tab.c"
    break;

  case 64: /* term: factor  */
#line 660 "src/sintatico.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 2966 "src/sintatico.tab.c"
    break;

  case 65: /* factor: '(' expression ')'  */
#line 664 "src/sintatico.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2972 "src/sintatico.tab.c"
    break;

  case 66: /* factor: ID  */
#line 665 "src/sintatico.y"
         {
        (yyval.node) = create_node((yyvsp[0].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[0].token).line;
        (yyval.node)->column = (yyvsp[0].token).columns;
        search_undeclared_node((yyval.node), symbol_table, &scope_stack);
        assign_types((yyval.node), symbol_table, &scope_stack);
    }
#line 2985 "src/sintatico.tab.c"
    break;

  case 67: /* factor: INT  */
#line 673 "src/sintatico.y"
          {
        (yyval.node) = create_node((yyvsp[0].token).body);
        (yyval.node)->line = (yyvsp[0].token).line;
        (yyval.node)->column = (yyvsp[0].token).columns;
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        strcpy((yyval.node)->type, "int"); 
    }
#line 2997 "src/sintatico.tab.c"
    break;

  case 68: /* factor: FLOAT  */
#line 680 "src/sintatico.y"
            {
        (yyval.node) = create_node((yyvsp[0].token).body);
        (yyval.node)->line = (yyvsp[0].token).line;
        (yyval.node)->column = (yyvsp[0].token).columns;
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        strcpy((yyval.node)->type, "float");
    }
#line 3009 "src/sintatico.tab.c"
    break;

  case 69: /* factor: ID '(' arguments_list ')'  */
#line 687 "src/sintatico.y"
                                {
        (yyval.node) = create_node("factor_arguments");
        (yyval.node)->node1 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node2 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node1->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->node1->line = (yyvsp[-3].token).line;
        (yyval.node)->node1->column = (yyvsp[-3].token).columns;
        function_param_amount(symbol_table,arg_counter,(yyvsp[-3].token).body, (yyvsp[-3].token).line, (yyvsp[-3].token).columns);
        arg_counter = 0;
        search_undeclared_node((yyval.node)->node1, symbol_table, &scope_stack);
        assign_types((yyval.node)->node1, symbol_table, &scope_stack);
    }
#line 3027 "src/sintatico.tab.c"
    break;

  case 70: /* factor: LIST_CONSTANT  */
#line 700 "src/sintatico.y"
                    {
        (yyval.node) = create_node((yyvsp[0].token).body);
        (yyval.node)->line = (yyvsp[0].token).line;
        (yyval.node)->column = (yyvsp[0].token).columns;
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        strcpy((yyval.node)->type, "NIL");
    }
#line 3039 "src/sintatico.tab.c"
    break;

  case 71: /* factor: unary_factor  */
#line 707 "src/sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 3045 "src/sintatico.tab.c"
    break;

  case 72: /* arguments: arguments_list ',' expression  */
#line 711 "src/sintatico.y"
                                  {
        (yyval.node) = create_node("arguments");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = (yyvsp[0].node); 
        arg_counter++;
    }
#line 3056 "src/sintatico.tab.c"
    break;

  case 73: /* arguments: expression  */
#line 717 "src/sintatico.y"
                 {
        (yyval.node) = create_node("arguments");
        (yyval.node)->node1 = (yyvsp[0].node);
        arg_counter++;
    }
#line 3066 "src/sintatico.tab.c"
    break;

  case 74: /* arguments_list: arguments  */
#line 725 "src/sintatico.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 3072 "src/sintatico.tab.c"
    break;

  case 75: /* arguments_list: %empty  */
#line 726 "src/sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 3080 "src/sintatico.tab.c"
    break;

  case 76: /* unary_factor: BINARY_BASIC_OP1 factor  */
#line 732 "src/sintatico.y"
                            {
        (yyval.node) = create_node("unary_factor");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_unary((yyval.node)->node1, (yyval.node), (yyval.node)->node2);
    }
#line 3095 "src/sintatico.tab.c"
    break;

  case 77: /* unary_factor: TAIL factor  */
#line 742 "src/sintatico.y"
                 {
        (yyval.node) = create_node("unary_factor");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_unary((yyval.node)->node1, (yyval.node), (yyval.node)->node2);
    }
#line 3110 "src/sintatico.tab.c"
    break;

  case 78: /* unary_factor: HEADER factor  */
#line 752 "src/sintatico.y"
                   {
        (yyval.node) = create_node("unary_factor");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
        (yyval.node)->line = (yyvsp[-1].token).line;
        (yyval.node)->column = (yyvsp[-1].token).columns;

        evaluate_unary((yyval.node)->node1, (yyval.node), (yyval.node)->node2);
    }
#line 3125 "src/sintatico.tab.c"
    break;


#line 3129 "src/sintatico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 764 "src/sintatico.y"


void yyerror(const char* msg){
    printf(BRED"(%d|%d) ", line, columns);
    printf("Syntax error: ");
    printf("%s\n"RESET, msg);
    errors++;
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
        free_node(root);
    }
    fclose(yyin);    
    yylex_destroy();

    return 0;
}
