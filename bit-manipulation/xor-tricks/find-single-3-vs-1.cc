#include <cstring>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto &n: nums){
            ones ^= (n & ~twos);
            twos ^= (n & ~ones);
        }
        return ones;
    }
};