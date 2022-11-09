int main() {
    set s;
    s = EMPTI;

    // add(1 in s);
    // add(2 in s);
    // add(5 in s);
    // add(8 in s);

    add(1 in add(2 in add(5 in add(8 in s)))); / aLTERNATIVA

    set possibleSums;
    possibleSums = EMPTY;
    int %;
    
    forall (% in s) {
        set sumsWithX;   
        sumsWithX = EMPTY;
        int val;
        forall (val in possibleSums) add((% + val) in sumsWithX);
        forall (val in sumsWithX) add (val in possibleSums);
        if (13 in possibleSums) writeln("y"); else writeln("n');
    }
}