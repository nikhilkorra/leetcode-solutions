class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, diff = 0, startIdx = 0;
        for(int i = 0; i < n; i++){
            diff += (gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
            if(diff < 0){
                startIdx = i + 1;
                diff = 0;
            }
        }
        if(sum < 0) return -1;
        return startIdx;
    }
};