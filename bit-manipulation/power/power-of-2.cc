class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n <= 0) return false;
        // if(n == 1) return true;
        // return n%2 == 0 && isPowerOfTwo(n / 2);
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};