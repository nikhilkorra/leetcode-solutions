class Solution {
public:
    vector<int> min_path;
    int min_diff = INT_MAX;
    void dfs(vector<int> &divs, vector<int> &path, long long prod, int i, int &k, int &n){
        if(path.size() > k) return;
        if(path.size() == k){
            if(prod == n){
                // for(auto &p : path) cout<<p<<' ';
                // cout<<endl;
                int diff = path[k - 1] - path[0];
                if(diff < min_diff){
                    min_diff = diff;
                    min_path = path;
                }
            }
            return;
        }
        while(i < divs.size()){
            if(prod * divs[i] > n) break;
            path.push_back(divs[i]);
            dfs(divs, path, prod * divs[i], i, k, n);
            i++;
            path.pop_back();
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int> divs;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                if(n / i == i) divs.push_back(i);
                else{
                    divs.push_back(i);
                    divs.push_back(n / i);
                }
            } 
        }
        // for(auto x: divs) cout<<x<<' ';
        // cout<<endl;
        sort(divs.begin(), divs.end());
        vector<int> path;
        dfs(divs, path, 1, 0, k, n);
        return min_path;
    }
};