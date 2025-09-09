class Solution {
public:
    int msb(int x){
        return x ? 31 - __builtin_clz(x) : 0;
    }
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = 1;
        if(dividend < 0) sign = -sign;
        if(divisor < 0) sign = -sign;
        unsigned int L = abs(static_cast<long>(dividend));
        unsigned int D = abs(static_cast<long>(divisor));
        int lenL = msb(L), lenD = msb(D);
        int shift = lenL - lenD;
        unsigned int quotient = 0;
        int temp = 0;
        while(shift >= 0){
            if(L - temp >= (D << shift)){
                temp += (D << shift);
                quotient |= (1 << shift);
            }
            shift--;
        }
        return sign * quotient;
    }
};