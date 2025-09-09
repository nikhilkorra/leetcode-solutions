class Solution {
public:
    string longestPalindrome(string s){
        int n = s.length();
        int N = 2*n + 1;
        vector<int> p(N, 1);
        for(int i = 0; i <= n; i++){
            s.insert(2*i, 1, '#');
        }
        int l = 1, r = 1, mirror = 0, index = 0, maxlen = -1;
        for(int i = 1; i < N; i++){
            mirror = l + r - i;
            if(i < r){
                p[i] = max(0, min(p[mirror], r - i));
            }
            while((i + p[i] < N) && (i - p[i] >= 0) && (s[i + p[i]] == s[i - p[i]])){
                p[i]++;
            }
            if(p[i] > maxlen){
                maxlen = p[i] - 1;
                index = i/2 - (p[i] - 1)/2;
            }
            if(i + p[i] > r){
                l = i - p[i];
                r = i + p[i];
            }
        }
        for(int i = 0; i <= n; i ++) s.erase(i, 1);
        return s.substr(index, maxlen);
    }
    
    string longestPalindromeDP(string s) {
        int n = s.length(), index = 0, maxlen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int i = 0; i < n; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                index = i;
                maxlen = 2;
            }
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i <= n - l; i++){
                int j = i + l - 1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    index = i;
                    maxlen = l;
                }
            }
        }
        return s.substr(index, maxlen);
    }
};