class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto &e: prerequisites){
            indegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        queue<int> nodes;
        for(int u = 0; u < numCourses; u++){
            if(indegree[u] == 0){
                nodes.push(u);
            }
        }
        int ctr = 0;
        vector<int> deleted(numCourses, false);
        while(!nodes.empty()){
            int qsize = nodes.size();
            while(qsize--){
                int u = nodes.front();
                nodes.pop();
                deleted[u] = true;
                for(auto v: adj[u]){
                    if(!deleted[v]){
                        indegree[v]--;
                        if(indegree[v] == 0){
                            nodes.push(v);
                        }
                    }
                }
                ctr++;
            }
        }
        return ctr == numCourses;
    }
};