class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1, max_area=-1;
        while(l<r){
            int area = min(height[l], height[r])*(r-l);
            if(max_area < area) max_area = area;
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return max_area;
    }
};