class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> m;
        for(auto &k : t) m[k]++;
        int l = 0, r = l, matchlen = t.length(), minlen = INT_MAX;
        string res = "";
        while(r < s.length()){
            m[s[r]]--;
            if(m[s[r]] >= 0) matchlen--;
            if(matchlen == 0){
                while(m[s[l]] < 0) m[s[l++]]++;
                if(minlen > r - l + 1){
                    minlen = r - l + 1;
                    res = s.substr(l, r - l + 1);
                }
                m[s[l++]]++;
                matchlen++;
            }
            r++;
        }
        return res;
    }
};