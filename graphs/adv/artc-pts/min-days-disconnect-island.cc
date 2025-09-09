class Solution {
public:
    int dfs_time = 0;
    int dfs(int n, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, int &numPoints){
        dfs_time = 0;
        int cc = 0;
        for(int u = 1; u < n; u++){
            if(disc[u] == -1){
                cc++;
                dfsVisit(u, adj, disc, low, -1, numPoints);
            }
        }
        return cc;
    }
    void dfsVisit(int u, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, int parent, int &numPoints){
        disc[u] = low[u] = ++dfs_time;
        int children = 0;
        for(auto &v: adj[u]){
            if(disc[v] == -1){
                children++;
                dfsVisit(v, adj, disc, low, u, numPoints);
                low[u] = min(low[u], low[v]);
                if((parent == -1 && children > 1) ||\
                   (parent != -1 && disc[u] <= low[v])){
                    numPoints++;
                }
            }
            else if(v != parent){
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    int articulationPoints(int n, vector<vector<int>> &adj){
        int numPoints = 0;
        vector<int> disc(n, -1), low(n, -1);
        int val = dfs(n, adj, disc, low, numPoints);
        // cout<<val<<' '<<numPoints<<endl;
        return val > 1 ? -1 : numPoints;
    }
    void addEdge(int i, int j, int M, int N, vector<vector<int>> &grid, vector<vector<int>> &adj){
        
    }
    int minDays(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        unordered_map<int, int> m;
        vector<vector<int>> adj;
        adj.push_back(vector<int>());
        int V = 1;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 1){
                    int u = N*i + j;
                    if(m[u] == 0){
                        m[u] = V++;
                        adj.push_back(vector<int>());
                    }
                    if(i < M - 1 && grid[i + 1][j] == 1){
                        if(m[u + N] == 0){
                            m[u + N] = V++;
                            adj.push_back(vector<int>());
                        }
                        adj[m[u]].push_back(m[u + N]);
                    }
                    if(i > 0 && grid[i - 1][j] == 1){
                        if(m[u - N] == 0){
                            m[u - N] = V++;
                            adj.push_back(vector<int>());
                        }
                        adj[m[u]].push_back(m[u - N]);
                    }
                    if(j < N - 1 && grid[i][j + 1] == 1){
                        if(m[u + 1] == 0){
                            m[u + 1] = V++;
                            adj.push_back(vector<int>());
                        }
                        adj[m[u]].push_back(m[u + 1]);
                    }
                    if(j > 0 && grid[i][j - 1] == 1){
                        if(m[u - 1] == 0){
                            m[u - 1] = V++;
                            adj.push_back(vector<int>());
                        }
                        adj[m[u]].push_back(m[u - 1]);
                    }
                }
            }
        }
        // for(int u = 1; u < V; u++){
        //     cout<<u<<"-> ";
        //     for(auto &v: adj[u]){
        //         cout<<v<<", ";
        //     }
        //     cout<<endl;
        // }
        if(V <= 2) return V-1;
        int numPoints = articulationPoints(V, adj);
        if(numPoints == -1) return 0;
        if(numPoints >= 1) return 1;
        return 2;
    }
};