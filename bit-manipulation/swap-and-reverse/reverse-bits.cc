class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        int bits = 31;
        while(bits >= 15){
            reversed |= ((n & (1 << bits)) ? (1 << (31 - bits)) : 0);
            reversed |= ((n & (1 << 31 - bits)) ? (1 << bits) : 0);
            bits--;
        }
        return reversed;
    }
};