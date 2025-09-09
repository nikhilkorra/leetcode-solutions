#define pi pair<int, int>
class Solution {
public:
    vector<vector<pi>> inverse_query;
    vector<int> colour;
    int find(int u, vector<int> &parent){
        if(parent[u] != u){
            parent[u] = find(parent[u], parent);
        }
        return parent[u];
    }
    void dfs(int u, vector<int> &parent, vector<vector<pi>> &adj, vector<vector<int>> &freq, vector<int> &path, vector<int> &lca){
        colour[u] = 1;
        freq[u] = path;
        for(auto &[v, w] : adj[u]){
            // auto [v, w] = edge;
            if(colour[v] != 0)
                continue;
            path[w] += 1;
            dfs(v, parent, adj, freq, path, lca);
            path[w] -= 1;
            parent[v] = u;
        }
        for(auto &[v, i] : inverse_query[u]){
            if(u == v || colour[v] == 2){
                lca[i] = find(v, parent);
            }
        }
        colour[u] = 2;
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> freq(n, vector<int>(27, 0));
        inverse_query.resize(n, vector<pi>());
        colour.resize(n, 0);
        int m = queries.size();
        for(int i = 0; i < m; i++){
            int u = queries[i][0], v = queries[i][1];
            // int u = query[0], v = query[1];
            inverse_query[u].push_back({v, i});
            if(u != v){
                inverse_query[v].push_back({u, i});
            }
        }
        vector<vector<pi>> adj(n, vector<pi>());
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int root = 0;
        vector<int> path(27, 0);
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        vector<int> lca(m, 0);
        dfs(root, parent, adj, freq, path, lca);
        vector<int> minOps;
        for(int i = 0; i < m; i++){
            int u = queries[i][0], v = queries[i][1];
            int maxFreq = 0;
            int totalW = 0, currW = 0;
            for(int j = 1; j <= 26; j++){
                currW = freq[u][j] + freq[v][j] - 2*freq[lca[i]][j];
                totalW += currW;
                maxFreq = max(maxFreq, currW);
            }
            minOps.push_back(totalW - maxFreq);
        }
        return minOps;
    }
};