float list unique_list(int a) {
    float elem;
    float list new_list;
    new_list = NIL;
    writeln("Digite um novo elemento da lista:");
    read(elem);
    new_list = elem : new_list;
    return new_list;
}

int main(){
    writeln("Lista com head e tail");
    float list float_list;
    float_list = unique_list;
    write(?unique_list);
    write(%unique_list);

    return 0;
}