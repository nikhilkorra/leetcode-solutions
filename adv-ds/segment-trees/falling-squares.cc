class Solution {
public:
    vector<int> t, lazy;

    int maxRange(int v, int tl, int tr, int l, int r){
        if(l > r) return INT_MIN;
        if(l == tl && r == tr) return t[v];
        push(v);
        int mid = (tl + tr)/2;
        return max(maxRange(2*v, tl, mid, l, min(r, mid)),\
               maxRange(2*v + 1, mid + 1, tr, max(l, mid + 1), r));
    }

    void push(int v){
        if(lazy[v] != 0){
            t[2*v] = lazy[v];
            t[2*v + 1] = lazy[v];
            lazy[2*v] = lazy[v];
            lazy[2*v + 1] = lazy[v];
        }
        lazy[v] = 0;
    }

    void update(int v, int increment, int tl, int tr, int l, int r){
        if(l > r) return;
        if(l == tl && r == tr){
            t[v] = increment;
            lazy[v] = increment;
            return;
        }
        push(v);
        int mid = (tl + tr)/2;
        update(2*v, increment, tl, mid, l, min(mid, r));
        update(2*v + 1, increment, mid + 1, tr, max(mid + 1, l), r);
        t[v] = max(t[2*v], t[2*v + 1]);
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        // set<int> s;
        // for(auto &p: positions){
        //     s.insert(p[0]);
        //     s.insert(p[0] + p[1] - 1);
        // }
        // int n = s.size();
        vector<int> x;
        for(auto &p: positions){
            x.push_back(p[0]);
            x.push_back(p[0] + p[1] - 1);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        unordered_map<int, int> m;
        for(auto &i: x) m[i] = (&i - &x[0]);
        int n = x.size();
        t.resize(4*n, 0);
        lazy.resize(4*n, 0);
        vector<int> res;
        int totalMax = 0;
        for(auto &p: positions){
            int left = p[0];
            int sideLength = p[1];
            // int l = distance(s.begin(), s.find(p[0]));
            // int r = distance(s.begin(), s.find(p[0] + p[1] - 1));
            int l = m[p[0]], r = m[p[0] + p[1] - 1];
            int currMax = maxRange(1, 0, n-1, l, r);
            update(1, currMax + p[1], 0, n-1, l, r);
            totalMax = max(currMax + p[1], totalMax);
            res.push_back(totalMax);
        }
        return res;
    }
};