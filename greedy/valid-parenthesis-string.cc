class Solution {
public:
    bool checkValidString(string s) {
        int max_open = 0, min_open = 0;
        for(char c: s){
            if(c == '('){
                max_open++; min_open++;
            }
            if(c == ')'){
                max_open--; min_open--;
            }
            if(c == '*'){
                max_open++; min_open--;
            }
            if(max_open < 0) return false;
            min_open = max(min_open, 0);
        }
        return min_open == 0;
    }
};