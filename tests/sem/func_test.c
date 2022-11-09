float func(int a, int b){
    return a + b;
}

int main(){
    int a;
    a = func(1.0, (2 + (3.0)));
    return a;
}