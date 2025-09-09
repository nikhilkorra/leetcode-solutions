#define pii pair<int, pair<int, int>>
#define INF 100001

struct compare{
    bool operator()(const pii &a, const pii &b){
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pii, vector<pii>, compare> pq;
        int k = nums.size(), cmax = -INF;
        for(int i = 0; i < k; i++){
            cmax = cmax < nums[i][0] ? nums[i][0] : cmax; 
            pq.push({nums[i][0], {i, 0}});
        }
        int low = INF, high = 0, minRange = 2*INF;
        while(pq.size()){
            pii top = pq.top();
            pq.pop();
            int i = top.second.first, j = top.second.second;
            int cmin = nums[i][j];
            if(cmax - cmin < minRange || (cmax - cmin == minRange && cmin < low)){
                low = cmin;
                high = cmax;
                minRange = cmax - cmin;
            }
            if(j < nums[i].size() - 1){
                pq.push({nums[i][j+1], {i, j+1}});
                cmax = cmax < nums[i][j+1] ? nums[i][j+1] : cmax;
            }
            else break;
        }
        return {low, high};
    }
};