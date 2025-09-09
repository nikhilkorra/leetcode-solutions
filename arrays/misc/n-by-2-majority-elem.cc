class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = nums[0], count = 0;
        for(auto &num : nums){
            if(elem == num) count++;
            else count--;
            if(count < 0){
                elem = num;
                count = 1;
            }
        }
        return elem;
    }
};