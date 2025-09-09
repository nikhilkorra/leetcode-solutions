class Solution {
public:
    pair<int, int> coinChangeAux(vector<vector<pair<int, int>>> &dp, vector<int>& coins, int i, int j){
        if(j<0 || i<0) return {-1, 0};
        if(dp[i][j].second!=INT_MAX) return dp[i][j];
        if(i==0){
            dp[i][j]={1, 0};
            return {1, 0};
        }

        int count = INT_MAX;

        pair<int,int> p1 = coinChangeAux(dp, coins, i-coins[j], j);
        int flag1 = p1.first;
        int num1 = p1.second;
        if(flag1==1) count = min(count, num1+1);

        pair<int, int> p2 = coinChangeAux(dp, coins, i, j-1);
        int flag2 = p2.first;
        int num2 = p2.second;
        if(flag2==1) count = min(count, num2);
        if(flag1==-1 && flag2==-1){
            dp[i][j]={-1,0};
            return {-1, 0};
        }
        dp[i][j]={1, count};
        return {1, count};
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<pair<int, int>>> dp(amount+1, vector<pair<int, int>>(n, {0, INT_MAX}));
        pair<int, int> p = coinChangeAux(dp, coins, amount, n-1);
        int flag = p.first;
        int num = p.second; 
        if(flag==-1) return flag;
        return num;
    }
};