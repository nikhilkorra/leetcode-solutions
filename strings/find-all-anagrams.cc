class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length() < p.length()) return res;
        int freq[26], window_freq[26];
        memset(freq, 0, sizeof(freq));
        memset(window_freq, 0, sizeof(window_freq));
        for(auto &k : p) freq[k - 'a']++;
        int l = 0, r = l, matchlen = 0;
        while(r < p.length()){
            window_freq[s[r] - 'a']++;
            if(window_freq[s[r] - 'a'] <= freq[s[r] - 'a']){
                matchlen++;
            }
            r++;
        }
        if(matchlen == p.length()) res.push_back(l);
        while(r < s.length()){
            window_freq[s[r] - 'a']++;
            if(window_freq[s[r] - 'a'] <= freq[s[r] - 'a']){
                matchlen++;
            }
            if(window_freq[s[l] - 'a'] <= freq[s[l] - 'a']){
                matchlen--;
            }
            window_freq[s[l] - 'a']--;
            l++;
            r++;
            if(matchlen == p.length()) res.push_back(l);

        }
        return res;
    }
};