class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, baskets=2, max_fruits=0, n=fruits.size();
        map<int, int> m;
        for(int i=0; i<n; i++) m[fruits[i]]=0;
        while(r<n){
            baskets=baskets<=2?baskets:2;
            if(m[fruits[r]]==0){
                if(baskets>0){
                    max_fruits=max(max_fruits, r-l+1);
                    m[fruits[r]]++;
                    r++;
                    baskets--;
                }
                else{
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0) baskets++;
                    l++;
                }
            }
            else{
                max_fruits=max(max_fruits, r-l+1);
                m[fruits[r]]++;
                r++;
            }
        }
        max_fruits=max(max_fruits, (r-l));
        return max_fruits;
    }
};