class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral(m * n);
        int l = 0, r = n - 1;
        int u = 0, d = m - 1;
        int idx = 0;
        while(l <= r && u <= d){
            // cout<<"lr ";
            for(int i = l; i <= r; i++){
                spiral[idx++] = matrix[u][i];
            }
            if(u == d) break;
            // cout<<"ud ";
            for(int i = u + 1; i <= d; i++){
                spiral[idx++] = matrix[i][r];
            }
            if(l == r) break;
            // cout<<"rl ";
            for(int i = r - 1; i >= l; i--){
                spiral[idx++] = matrix[d][i];
            }
            // cout<<"du "<<endl;
            for(int i = d - 1; i >= u + 1; i--){
                spiral[idx++] = matrix[i][l];
            }
            l++; r--;
            u++; d--;
        }
        return spiral;
    }
};