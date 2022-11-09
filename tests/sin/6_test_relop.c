int main(){

    set meuSet;

    meuSet = EMPTY;

    if( meuSet == EMPTY && meuSet > 1 || meuSet < 2 && meuSet == 5 || meuSet > 2)
        add(5 in meuSet);
    else
        write("ERRRO");
    
    writeln("minhaString");
    writeln('a');
    if ( 5 in meuSet ) {
        write("5 dentro");
    } else {
        write("5 fora");
    }

    if(exists(5 in meuSet)) {
        write("5 existe!");
    } else {
        forall(x in s){
            writeln(x);
        }
    }

    add(1 in s);
    add(add(1 in s) in s);
}