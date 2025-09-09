class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int count = 1;
        int n = intervals.size();
        int k = 0;
        for(int m = 1; m < n; m++){
            int s = intervals[m][0], f = intervals[k][1];
            if(s >= f){
                k = m;
                count++;
            }
        }
        return n - count;
    }
};