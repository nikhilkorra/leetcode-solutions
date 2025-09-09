class NumArray {
private:
    vector<int> ST;
    int n;
public:
    int build(vector<int>& nums, int v, int tl, int tr){
        if(tl == tr) return this->ST[v] = nums[tl];
        int mid = (tl + tr)/2;
        int sum1 = build(nums, 2*v, tl, mid);
        int sum2 = build(nums, 2*v + 1, mid + 1, tr);
        return this->ST[v] = (sum1 + sum2); 
    }
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        ST.resize(4*nums.size(), 0);
        build(nums, 1, 0, n - 1);
    }
    
    void updateHelper(int index, int val, int v, int tl, int tr){
        if(tl == tr){
            this->ST[v] = val;
            return;
        }
        int mid = (tl + tr)/2;
        if(index <= mid)
            updateHelper(index, val, 2*v, tl, mid);
        else
            updateHelper(index, val, 2*v + 1, mid + 1, tr);
        this->ST[v] = this->ST[2*v] + this->ST[2*v + 1];
        return;
    }
    void update(int index, int val) {
        updateHelper(index, val, 1, 0, this->n - 1);
    }
    
    int sumRangeHelper(int v, int tl, int tr, int l, int r){
        if(l > r) return 0;
        if(l == tl && r == tr) return this->ST[v];
        int mid = (tl + tr)/2;
        // if(r < tl) return sumRangeHelper(2*v, tl, mid, l, r);
        // if(l > tr) return sumRangeHelper(2*v + 1, mid + 1, tr, l, r);
        // return sumRangeHelper(2*v, tl, mid, l, mid) + \
        //        sumRangeHelper(2*v + 1, mid + 1, tr, mid + 1, r);
        return sumRangeHelper(2*v, tl, mid, l, min(mid, r)) + \
               sumRangeHelper(2*v + 1, mid + 1, tr, max(mid+1, l), r);
    }
    int sumRange(int left, int right) {
        return sumRangeHelper(1, 0, this->n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */