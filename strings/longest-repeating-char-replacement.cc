class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = -1, max_wnd_freq = 0;
        int l = 0, r = 0;
        int freq[26];
        while(r < s.length()){
            int right_idx = s[r] - 'A';
            int left_idx = s[l] - 'A';
            freq[right_idx]++;
            max_wnd_freq = max(max_wnd_freq, freq[right_idx]);
            int wdw_len = r - l + 1;
            if(wdw_len - max_wnd_freq <= k) 
                max_len = max(max_len, r - l + 1);
            else{
                freq[left_idx]--;
                // for(int i = l; i < r; i++){
                //    max_wnd_freq = max(max_wnd_freq, freq[i]); 
                // }
                l++;
            }
            r++;
        }
        return max_len;
    }
};