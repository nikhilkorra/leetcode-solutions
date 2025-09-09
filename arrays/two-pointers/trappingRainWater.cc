class Solution {
public:
    int trap(vector<int>& height){
        int n = height.size();
        int l=0, r=n-1, lmax=0, rmax=0, water=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<lmax) water+=(lmax-height[l]);
                else lmax=height[l];
                l++;
            }
            else{
                if(height[r]<rmax) water+=(rmax-height[r]);
                else rmax=height[r];
                r--;
            }
        }
        return water;
    }

    int trapStack(vector<int>& height) {
        int n=height.size();
        stack<int> s;
        int l=0, r=1;
        int curr=height[0], water=0;
        while(r<n){
            while(r<n && height[r-1]<=height[r]) r++;
            l=r-1;
            curr=height[l];
            while(r<n && curr>height[r]){
                s.push(height[r]);
                r++;
            }
            if(r<n){
                while(!s.empty()){
                    water+=(curr - s.top());
                    s.pop();
                }
            }
            l=r;
        }
        curr=-1;
        while(!s.empty()){
            if(s.top()>curr) curr=s.top();
            else water+=(curr-s.top());
            s.pop();

        }
        return water;
    }
};