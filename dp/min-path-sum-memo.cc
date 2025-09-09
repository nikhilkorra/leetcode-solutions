class Solution {
public:
    int minpathSumAux(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        if(i==0&&j==0) return grid[i][j];
        int lsum=INT_MAX, rsum=INT_MAX;
        if(i>0) lsum=minpathSumAux(grid, dp, i-1, j);
        if(j>0) rsum=minpathSumAux(grid, dp, i, j-1);
        dp[i][j]=grid[i][j] + min(lsum, rsum);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=0;
        if(m>0) n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        return minpathSumAux(grid, dp, m-1, n-1); 
    }
};