int main(){
    int a;
    {
        int a;
        {
            int a;
            {
                a = 2;
            }
            a = 10;
        }
        a = 20;
    }
    a = 30 * 2 / 1 + a + main();

    if( a == 10 )
        writeln("oops...");
    
    if( a < 0 && a > 10 && a != 0 || a != 10)
        writeln("a....");
}