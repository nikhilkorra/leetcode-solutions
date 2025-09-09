class Solution {
public:
    int msb(int x){
        return x ? 31 - __builtin_clz(x) : -1;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        int n = msb(left);
        if(n != msb(right)) return 0;
        int res = 0;
        while(n){
            int l = left & (1 << n);
            int r = right & (1 << n);
            if(l ^ r)
                break;
            if(l) res |= (1 << n);
            n--;
        }
        return res;
    }
};