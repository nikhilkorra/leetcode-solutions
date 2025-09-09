#define ll long long

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        map<ll, int> m;
        pq.push(1);
        int uglyNumber;
        while(n--){
            uglyNumber = pq.top();
            pq.pop();
            for(auto &factor: factors){
                ll num = (long long) factor * uglyNumber;
                if(m[num] == 0){
                    pq.push(num);
                    m[num] = 1;
                }
            }
        }
        return uglyNumber;
    }
};