class Solution {
public:
    int minimumTotal2D(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> sum(n+1, vector<int>(n+1, INT_MAX));
        sum[1][1]=triangle[0][0];
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                sum[i][j]=min(sum[i-1][j], sum[i-1][j-1])+triangle[i-1][j-1];
            }
        }
        int res = INT_MAX;
        for(int i=1; i<=n; i++){
            res = min(res, sum[n][i]);
        }
        return res;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> psum(n+1, INT_MAX);
        vector<int> csum(n+1, INT_MAX);
        psum[1]=triangle[0][0];
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                csum[j]=min(psum[j], psum[j-1])+triangle[i-1][j-1];
            }
            psum=csum;
        }
        int res = INT_MAX;
        for(int i=1; i<=n; i++){
            res = min(res, psum[i]);
        }
        return res;
    }
};