class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, min_len=INT_MAX, sum=0, n=nums.size();
        while(r<=n){
            // if(l>r) r=l;
            if(sum>=target){
                min_len=min(min_len, r-l);
                sum-=nums[l];
                l++;
            }
            else{
                if(r<n) sum+=nums[r];
                r++;
            }
        }
        return min_len==INT_MAX?0:min_len;
    }
};