int a(){return 0;}

int fatorial(int n){
    if(n==0)
        return 0;
    
    return n * fatorial(n - 1);
}

int main(){
    int i;
    int n;
    n = fatorial(10);
    int sum;
    sum = 0;
    set c;

    { int c; c = 10; }
    {
        {
            int c;
            {
                c = 2;
            }
            c = 4;
        }
    }

    for( i = 1; i < 10; ){
        sum = sum + i;
        i = i + 1;
    }

    if( sum > 100 ) writeln("Passou do limite exigido.");
    else if ( sum == 0 ) writeln("Não é pra chegar nesse caso.");
    else {
        writeln("E nem nesse...");
        write('\n');
    }

    if( sum == 100 && c == EMPTY ) {

    }

    return 0;
}