class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int swapIdx = n - 1;
        while(swapIdx > 0 && nums[swapIdx] <= nums[swapIdx - 1]){
            swapIdx--;
        }
        if(swapIdx == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int tailIdx = n - 1;
        while(tailIdx >= swapIdx && nums[tailIdx] <= nums[swapIdx - 1]){
            tailIdx--;
        }
        swap(nums[swapIdx - 1], nums[tailIdx]);
        reverse(nums.begin() + swapIdx, nums.end());
    }
};