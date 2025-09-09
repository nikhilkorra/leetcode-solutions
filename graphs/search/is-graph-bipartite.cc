class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1);
        for(int s = 0; s < graph.size(); s++){
            if(colour[s] != -1) continue;
            int V = graph.size();
            queue<int> q;
            q.push(s);
            colour[s] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v: graph[u]){
                    if(colour[v] == -1){
                        colour[v] = (colour[u] + 1)%2;
                        q.push(v);
                    }
                    else if(colour[u] == colour[v]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};