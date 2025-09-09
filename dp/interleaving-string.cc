class Solution {
public:
    int inlvaux(string s1, string s2, string s3, vector<vector<int>>& dp, int i, int j, int k){
        if(i>=0 && j>=0 && dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        if(k>=0){
            int res = 0;
            if(i>=0 && s1[i]==s3[k]){
                res = res || inlvaux(s1, s2, s3, dp, i-1, j, k-1);
            }
            if(j>=0 && s2[j]==s3[k]){
                res = res || inlvaux(s1, s2, s3, dp, i, j-1, k-1);
            }
            return dp[i+1][j+1]=res;
        }
        if(i<0&&j<0) return 1;
        return 0;
    }
    bool isInterleaveMem(string s1, string s2, string s3) {
        int m=s1.length(), n=s2.length(), o=s3.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return inlvaux(s1, s2, s3, dp, m-1, n-1, o-1);
    }

    bool isInterleave(string s1, string s2, string s3){
        int m=s1.length(), n=s2.length(), o=s3.length();
        if((m+n)!=o) return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int i=1; i<=m; i++) if(s1[i-1]==s3[i-1]) dp[i][0]=dp[i-1][0];
        for(int j=1; j<=n; j++) if(s2[j-1]==s3[j-1]) dp[0][j]=dp[0][j-1];
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                int k=i+j;
                if(s1[i-1]==s3[k-1]) dp[i][j] = dp[i][j] || dp[i-1][j];
                if(s2[j-1]==s3[k-1]) dp[i][j] = dp[i][j] || dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};