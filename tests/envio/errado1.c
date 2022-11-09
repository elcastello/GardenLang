set func(int a, int b, int c){ // não possui main

    int a; // redeclaração de variável
    float a; // redeclaração de variável

    int x;
    x = func(1);        // número errado de argumentos e tipo incorreto de atribuição.
    x = func(1, 2, 3);  // tipo incorreto de atribuição.
    {int b; b = 2;}

    b = 3; // variável não declarada

    b;      // erro sintático
    b '= 2; // erro léxico

    z = 8;
}