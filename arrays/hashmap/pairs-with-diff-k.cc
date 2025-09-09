class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            // if(freq.find(nums[i]-k)!=freq.end()){
            //     if(freq[nums[i]]==0) count++;
            // }
            // if(freq.find(nums[i]+k)!=freq.end()){
            //     if(freq[nums[i]]==0) count++;
            // }
            freq[nums[i]]++;
        }
        for(auto [num, f]: freq){
            if(k==0){
                if(f>1) count++;
            }
            else{
                if(freq.find(num+k)!=freq.end()) count++;
            }
        }
        return count;
    }
};