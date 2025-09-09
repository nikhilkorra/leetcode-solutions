#define MAX_SUM 1000
class Solution {
public:
    int targetAux(vector<int>& nums, int i, int sum, int target, vector<vector<int>>& dp){
        if(i == nums.size()){
            if(sum == target) return 1;
            return 0;
        }
        int absSum = (sum >= 0) ? sum : MAX_SUM - sum;
        if(dp[i][absSum] != -1) return dp[i][absSum];
        sum += nums[i];
        int pcount = targetAux(nums, i+1, sum, target, dp);
        sum -= 2*nums[i];
        int ncount = targetAux(nums, i+1, sum, target, dp);
        return dp[i][absSum] = pcount + ncount;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0, sum = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2*MAX_SUM + 1, -1));
        return targetAux(nums, 0, sum, target, dp);
    }
};