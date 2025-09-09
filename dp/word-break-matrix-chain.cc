class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        map<string, int> dict;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(auto &word : wordDict){
            dict[word] = 1;
        }
        for(int l = 1; l <= n; l++){
            for(int i = 0; i <= n - l; i++){
                int j = i + l - 1;
                if(dict[s.substr(i, j - i + 1)]){
                    dp[i][j] = true;
                    continue;
                }
                for(int k = i; k < j; k++){
                    if(dp[i][k] && dp[k+1][j]){
                        dp[i][j] = true;
                        continue;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};