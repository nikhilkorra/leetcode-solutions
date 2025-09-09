class NumArray {
private:
    vector<int> prefixsum;

public:
    NumArray(vector<int>& nums) {
        this->prefixsum.resize(nums.size()+1, 0);
        this->prefixsum[0]=nums[0];
        for(int i=1; i<=nums.size(); i++) {
            this->prefixsum[i]=this->prefixsum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return this->prefixsum[right+1]-this->prefixsum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */