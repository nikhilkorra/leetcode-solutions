class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int>(1, 0);
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> leaves;
        for(int u = 0; u < n; u++){
            if(degree[u] == 1){
                leaves.push(u);
                degree[u]--;
            }
        }
        vector<int> res;
        while(!leaves.empty()){
            res.clear();
            int qsize = leaves.size();
            while(qsize--){
                int u = leaves.front();
                leaves.pop();
                res.push_back(u);
                for(auto v: adj[u]){
                    degree[v]--;
                    if(degree[v] == 1)
                        leaves.push(v);
                }
            }
        }
        return res;

    }
};