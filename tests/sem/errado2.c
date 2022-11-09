set myFunction(int a, int b){

    int a; // redeclaração
    int b; // redeclaração
    return a + b; // tipo incorreto de retorno
}

int func(int a){

    if( a > 0 ) {
        return a;
    }

    // ausência do tipo de retorno.
}

int func2(int a){

    int i;

    for(i = 0; i < 100; i++){
        return i;
    }
}