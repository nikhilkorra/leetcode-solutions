class Solution {
public:
    int numTrees2D(int n) {
        vector<vector<int>> c(n+2, vector<int>(n+2, 0)); 
        for(int i=0; i<=n; i++) c[i][i]=1;
        for(int l=2; l<=n; l++){
            for(int i=1; i<=n-l+1; i++){
                int j=i+l-1;
                for(int r=i; r<=j; r++){
                    c[i][j]+=(c[i][r-1]+c[r+1][j]);
                }
            }
        }
        return c[1][n];
    }
    int numTrees(int n){
        vector<int> c(n+1, 0);
        c[0]=1;
        c[1]=1;
        for(int k=2; k<=n; k++){
            for(int i=1; i<=k; i++){
                c[k]+=(c[i-1]*c[k-i]);
            }
        }
        return c[n];
    }
};