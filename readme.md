# GardenLang

## About

This is a project for a compiler for a programming language developed in the Compilers course at University of
Brasilia (UnB)

It is based on the C language, but with new operations and data types included (such as the set data type).

The compiler **does not generate machine code**, but an intermediate language (Three Address Code). The virtual machine
used to interpret the code was ![virtual machine three address code](https://github.com/lhsantos/tac)

The project was composed by the stages of creation of the lexical, syntactic and semantic analyzer, respectively.
The grammar of the programming language can be seen here???

Flex in version `2.6.4` was used to create the lexical analyzer and bison was used in version `3.7`.

## Instructions

The compiler can either read from standard input or load a file.
`$ ./gardenLang <file_name>`

It also accepts the paremeter `--dotfile` to generate a dotfile representing the abstract syntax tree.
Graphviz can be used to visualize by executing the following command:
`$ dot -Tpng <dot-file> -o <png-file-name>`

## Examples

The following code will be used as an example.
As you can see, GardenLang does not support the standard C library and, because of this, it has its own functions, such
as `writeln()`.

```c
int fib(int n){
if (n <= 1){
return n;
}

    return fib(n - 1) + fib(n - 2);

}

int main(){
int n;
n = fib(10);

    writeln("The fib(10) is: ");
    writeln(n);

    return 0;

}
```

The three-code-address file (file.tac) generated will contain:

```c
.table
int n = 0

.code
// function: fib
fib:
add $0, // function: main
main:
mov n, $-1
println n
```

The abstract tree syntax (by using the flag `--dotfile`) will be:
![AST code example](https://github.com/elcastelar/GardenLang/blob/master/img-repo/example.png)

The following code has numerous lexical, syntactic and semantic errors that must be found by the GardenLang compiler.

```c
set func(int a, int b, int c){

    int a;
    float a;
    set s;

    int x;
    x = func(1);
    x = func(1, 2, 3);
    {int b; b = 2;}

    b = 3;

    b;
    b '= 2;

    z = 8

    return s;
}
```

The GardenLang compiler output will be:
```c
[FLEX] character not recognized: ' (15, 39)
Syntax error in: line 19, column 11:
-> Reason: unexpected KY_RETURN
[ERROR] Main function not declared!
[ERROR] Symbol redeclaration [a] (3,10)
[ERROR] Symbol redeclaration [a] (4,54)
[ERROR] Function [func] with incorrect number of arguments. Expected 3, Found 1. row 8 column 13
[ERROR] Cannot assign this type to variable [x] (8, 6)
[ERROR] Cannot assign this type to variable [x] (9, 96)

Errors found: 
- Lexical Errors:  1
- Syntatic Errors: 1
- Semantic Errors: 6
```

The GardenLang compiler has some macros to debug like:
`DEBUG_BISON`, `DEBUG_FLEX` and `DEBUG_TAC`.

## Issues
* There is no good register allocation strategy, so a function with more than 8 parameters (or the one supported by the interpreter) will result in undefined behavior.