class Solution {
public:
    vector<string> dfs(vector<vector<string>> &dp, set<string> &st, string &s, int i){
        if(i == s.length()) return {""};
        if(dp[i].size()) return dp[i];
        vector<string> res;
        for(int j = i + 1; j <= s.length(); j++){
            string w = s.substr(i, j - i);
            if(st.find(w) != st.end()){
                vector<string> tmp = dfs(dp, st, s, j);
                for(auto &t: tmp){
                    if(t == "") res.push_back(w);
                    else res.push_back(w + " " + t);
                }
            }
        }
        dp[i] = res;
        return dp[i];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<vector<string>> dp(s.length(), vector<string>());
        return dfs(dp, st, s, 0);
    }
};