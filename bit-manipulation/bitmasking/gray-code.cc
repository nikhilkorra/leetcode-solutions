#include <cmath>

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray = {0};
        for(int i = 1; i <= n; i++){
            int prevLen = pow(2, i - 1);
            for(int j = 0; j < prevLen; j++){
                gray.push_back(gray[prevLen - j - 1] | (1 << (i - 1)));
            }
        }
        return gray;
    }
};