class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        for(int i = 0; i < nums.size(); i++){
            mask ^= nums[i];
        }
        mask &= -static_cast<unsigned int>(mask);
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & mask)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        return {a, b};
    }
};