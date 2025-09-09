class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length() < 10) return res;
        unordered_map<int, int> seq_map;
        int char_map[26];
        char_map[0] = 0;
        char_map['C' - 'A'] = 1;
        char_map['T' - 'A'] = 2;
        char_map['G' - 'A'] = 3;
        int wnd_hash = 0, l = 0;
        while(l < 10){
            wnd_hash <<= 2;
            wnd_hash |= char_map[s[l] - 'A'];
            l++;
        }
        seq_map[wnd_hash] = 1;
        while(l < s.length()){
            wnd_hash <<= 2;
            wnd_hash |= char_map[s[l] - 'A'];
            wnd_hash &= 0xFFFFF;
            seq_map[wnd_hash]++;
            if(seq_map[wnd_hash] == 2){
                res.push_back(s.substr(l - 9, 10));
            }
            l++;
        }
        return res;
    }
};