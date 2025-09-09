class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.length(), max_len=0;
        unordered_map<int, int> c;
        while(r<n){
            while(c[s[r]]>0)
                c[s[l++]]--;
            c[s[r++]]=1;
            max_len=max(max_len, r-l);
        }
        return max_len;
    }
};