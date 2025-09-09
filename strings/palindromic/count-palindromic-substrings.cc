class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int N = 2*n + 1;
        vector<int> P(N, 0);
        int C = 1, R = 1;
        for(int i = 0; i <= n; i++) s.insert(2*i, 1, '#');
        for(int i = 1; i < N; i++){
            int mirror = 2*C - i;
            if(i < R){
                P[i] = min(P[mirror], R - i);
            }
            while((i + P[i] < N) && (i - P[i] >= 0) && (s[i + P[i]] == s[i - P[i]])){
                P[i]++;
            }
            if(i + P[i] > R){
                C = i;
                R = i + P[i];
            }
        }
        int res = 0;
        for(auto &p : P) res += p/2;
        return res;
    }
};