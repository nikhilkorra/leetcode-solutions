class Solution {
public:
    const int MOD = 1e9 + 7;
    int ndaux(string s, string t, vector<vector<int>>& dp, int i, int j){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = (ndaux(s, t, dp, i-1, j-1) + ndaux(s, t, dp, i-1, j));
        return dp[i][j]=ndaux(s, t, dp, i-1, j);
    }
    int numDistinctMem(string s, string t) {
        int m=s.length(), n=t.length();
        if(m<n) return 0;
        vector<vector<int>> dp (m, vector<int> (n, 0));
        return ndaux(s, t, dp, s.length()-1, t.length()-1);
    }

    int numDistinctStandard(string s, string t){
        int m=s.length(), n=t.length();
        if(m<n) return 0;
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        for(int i=0; i<m; i++) dp[i][0]=1;
        // for(int j=0; j<n; i++) dp[0][j]=0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] += dp[i-1][j]%MOD;
                if(s[i-1]==t[j-1]) dp[i][j] += dp[i-1][j-1]%MOD;
            }
        }
        return dp[m][n];
    }

    int numDistinct(string s, string t){
        int m=s.length(), n=t.length();
        if(m<n) return 0;
        vector<int> dp_prev(n+1, 0);
        vector<int> dp_new(n+1, 0);
        dp_prev[0]=1;
        dp_new[0]=1;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp_new[j] = dp_prev[j]%MOD;
                if(s[i-1]==t[j-1]) dp_new[j] += dp_prev[j-1]%MOD;
            }
            dp_prev = dp_new;
        }
        return dp_new[n];
    }
};