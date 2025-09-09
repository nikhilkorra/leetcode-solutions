class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = true;
        dfs(i, j-1, visited, grid); 
        dfs(i, j+1, visited, grid); 
        dfs(i-1, j, visited, grid); 
        dfs(i+1, j, visited, grid); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        int cc = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i, j, visited, grid);
                    cc++;
                }
            }
        }
        return cc;
    }
};