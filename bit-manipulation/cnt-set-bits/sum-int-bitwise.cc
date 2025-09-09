class Solution {
public:
    int getSumIterative(int a, int b) {
        int res = 0, carry = 0;
        for(int i = 0; i < 32; i++){
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            int sum = x ^ y ^ carry;
            carry = (x & y) | (carry & x) | (carry & y);
            res = res | (sum << i);
        }
        return res;
    }
    int getSum(int a, int b){
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};