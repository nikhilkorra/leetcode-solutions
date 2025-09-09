class Graph{
public:
    int V;
    vector<int> colour;
    vector<vector<int>> adj;
    vector<int> reverse_L;
    Graph(int n, vector<vector<int>> adj){
        V = n;
        this->adj = adj;
    }
    void dfs(){
        colour.resize(V, 0);
        for(int u = 0; u < V; u++){
            if(colour[u] == 0){
                dfs_util(u);
            }
        }
    }
    void dfs_util(int u){
        colour[u] = 1;
        for(auto &v: adj[u]){
            if(colour[v] == 0){
                colour[v] = 1;
                dfs_util(v);
            }
        }
        colour[u] = 2;
        reverse_L.push_back(u);
    }
    vector<int> toposort(){
        dfs();
        return reverse_L;
    }
};

class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int V = m * n;
        vector<vector<int>> adj(V, vector<int>());
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = i * n + j;
                if(i > 0 && matrix[i - 1][j] > matrix[i][j])
                    adj[idx].push_back(idx - n);
                if(j > 0 && matrix[i][j - 1] > matrix[i][j])
                    adj[idx].push_back(idx - 1);
                if(i < m - 1 && matrix[i + 1][j] > matrix[i][j])
                    adj[idx].push_back(idx + n);
                if(j < n - 1 && matrix[i][j + 1] > matrix[i][j])
                    adj[idx].push_back(idx + 1);
            }
        }
        Graph *G = new Graph(V, adj);
        vector<int> reverse_L = G->toposort();
        vector<int> max_reachable(V, 1);
        int max_len = 0;
        for(auto &u: reverse_L){
            int max_dist = 0;
            for(auto &v: adj[u])
                max_dist = max(max_dist, max_reachable[v]);
            max_reachable[u] += max_dist;
            max_len = max(max_len, max_reachable[u]);
        }
        return max_len;
    }
};