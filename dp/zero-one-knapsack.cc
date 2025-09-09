class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= W; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j - 1];
                if(i >= wt[j - 1]){
                    dp[i][j] = max((val[j - 1] + dp[i - wt[j - 1]][j - 1]), dp[i][j]);
                }
            }
        }
        return dp[W][n];
    }
};