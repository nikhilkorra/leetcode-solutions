#define pi pair<int, int>

struct compare{
    bool operator()(const pi &a, const pi &b){
        return a.second > b.second;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pi, vector<pi>, compare> pq;
        int V = points.size();
        vector<bool> visited(V, false);
        vector<int> key(V, INT_MAX);
        key[0] = 0;
        pq.push({0, 0});
        int cost = 0, ctr = 0;
        while(ctr < V){
            auto [i, weight] = pq.top();
            pq.pop();
            if(visited[i]) continue;
            cost += weight;
            visited[i] = true;
            for(int j = 0; j < V; j++){
                if(i != j && !visited[j]){
                    int xi = points[i][0], yi = points[i][1];
                    int xj = points[j][0], yj = points[j][1];
                    int dist = abs(xi - xj) + abs(yi - yj);
                    if(key[j] > dist){
                        key[j] = dist;
                        pq.push({j, dist});
                    }
                }
            }
            ctr++;
        }
        return cost;
    }
};