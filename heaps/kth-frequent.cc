class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> max_heap;
        int n=nums.size();
        unordered_map<int, int> freq;
        vector<int> res;
        for(int i=0; i<n; i++) freq[nums[i]]++;
        for(auto& [num, f]: freq) max_heap.push({f, num});
        while(k--){
            pair<int, int> p = max_heap.top();
            max_heap.pop();
            res.push_back(p.second);
        }
        return res;
    }
};