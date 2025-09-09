class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        unordered_map<int, int> prefix_count;
        prefix_count[0]=1;
        int sum=0, count=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(prefix_count.find(sum-k)!=prefix_count.end()){
                count+=prefix_count[sum-k];
            }
            prefix_count[sum]++;
        }
        return count;
    }
    int subarraySumNonNegative(vector<int>& nums, int k) {
        int l=0, r=0, n=nums.size();
        int sum=0, count=0;
        while(r<=n){
            if(sum<k){
                if(r>=n) break;
                sum+=nums[r];
                r++;
            }
            else{
                if(sum==k) count++;
                if(l>=n) break;
                sum-=nums[l];
                l++;
            }
        }
        return count;
    }
};