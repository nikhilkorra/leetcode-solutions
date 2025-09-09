class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> diff;
        diff[0]=-1;
        int zeros=0, ones=0, res=0, n=nums.size();
        for(int i=0; i<n; i++){
            zeros+=(nums[i]==0)?1:0;
            ones+=(nums[i]==1)?1:0;
            if(diff.find(zeros-ones)==diff.end()) diff[zeros-ones]=i;
            else{
                res=max(res, i-diff[zeros-ones]);
            }
        }
        return res;
    }
};