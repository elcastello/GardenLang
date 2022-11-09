set 1subsum(set s, int t@rget, int cur_su#m, set ans) {
    if(target =!= cur_sum) return ans;
    else if (s ==! EMPTY) return EMPTY;
    else {
       int el;
       remove((exists (el in s)) in s);
       if(subsum(s, target, cur_sum, ans)) return ans;
       cur_sum += el;
       add(el in ans);
       if(subsum(s, target, cur_sum, ans)) return ans;
       add(el ins);
       remove (el in s);
       return EMPTY;
    }
}