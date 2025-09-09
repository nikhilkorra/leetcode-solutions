class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_ct=0, one_ct=0, two_ct=0, n=nums.size();
        for(int k=0; k<n; k++){
            if(nums[k]==0){
                nums[zero_ct]=0;
                if(one_ct>0) nums[zero_ct+one_ct]=1;
                if(two_ct>0) nums[zero_ct+one_ct+two_ct]=2;
                zero_ct++;
            }
            else if(nums[k]==1){
                nums[zero_ct+one_ct]=1;
                if(two_ct>0) nums[zero_ct+one_ct+two_ct]=2;
                one_ct++;
            }
            else two_ct++;
        }
    }
};