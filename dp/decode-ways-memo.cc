class Solution {
public:
    int numDecodingAux(string s, vector<int>& dp, int i, int n){
        if(i>=n) return 1;
        if(dp[i]!=0) return dp[i];
        if(s[i]=='0') return dp[i]=0;
        if(s[i]>'2') return dp[i]=numDecodingAux(s, dp, i+1, n);
        if(i+1<n){
            if(s[i]=='1' || ((s[i]=='2') && s[i+1]<='6')){
                dp[i] = numDecodingAux(s, dp, i+1, n) + numDecodingAux(s, dp, i+2, n);
                return dp[i];
            }
        }
        return dp[i]=numDecodingAux(s, dp, i+1, n);
    }
    int numDecodings(string s) {
        int n=s.length();
        if(s[0]=='0') return 0;
        vector<int> dp(n, 0);
        return numDecodingAux(s, dp, 0, n);
    }
};