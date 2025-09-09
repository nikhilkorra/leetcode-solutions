#define pi pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pi>> adj(n + 1, vector<pi>());
        for(auto &e: times){
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, k});
        int max_time = 0, ctr = 0;
        while(!pq.empty()){
            auto [time, u] = pq.top();
            pq.pop();
            if(time > dist[u]) continue;
            max_time = max(max_time, time);
            for(auto [v, w]: adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
            ctr++;
        }
        return ctr == n ? max_time : -1;
    }
};