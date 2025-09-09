class Solution {
public:
    int ctoi(char c){
        return (int)(c - '0');
    }
    string removeKdigits(string num, int k) {
        string res = "";
        int m = num.length() - k;
        for(auto c : num){
            while(res.length() > 0 && k > 0 && c - '0' < res.back() - '0'){
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        while(k > 0){
            res.pop_back();
            k--;
        }
        // auto first_digit_pos = res.find_first_not_of('0');
        // return first_digit_pos != string::npos ? res.substr(first_digit_pos) : "0";
        int zero_trail = 0;
        while(zero_trail < m){
            if(res[zero_trail] != '0')
                break;
            zero_trail++;
        }
        if(zero_trail == m) return "0";
        return res.substr(zero_trail, m - zero_trail);
    }
};