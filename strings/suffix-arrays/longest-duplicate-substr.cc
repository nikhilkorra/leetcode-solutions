class SubstringRank {
public:
    int leftRank;
    int rightRank;
    int index;
};
bool cmp(SubstringRank &a, SubstringRank &b){
    if(a.leftRank != b.leftRank) return a.leftRank < b.leftRank;
    return a.rightRank < b.rightRank;
}
class Solution {
public:
    int ord(char c){
        return (int)(c - 'a') + 1;
    }
    void makeRanks(SubstringRank substrRank[], int *rank, int n){
        int r = 1;
        rank[substrRank[0].index] = r;
        for(int i = 1; i < n; i++){
            if((substrRank[i].leftRank != substrRank[i-1].leftRank) || \
                (substrRank[i].rightRank != substrRank[i-1].rightRank))
                r++;
            rank[substrRank[i].index] = r;
        }
    }
    int* computeSuffixArray(string t, int n){
        int *rank, *suffixArray;
        SubstringRank *substrRank = new SubstringRank[n];
        rank = (int *)malloc(sizeof(int) * n);
        suffixArray = (int *)malloc(sizeof(int) * n);

        for(int i = 0; i < n; i++){
            substrRank[i].leftRank = ord(t[i]);
            substrRank[i].rightRank = 0;
            if(i < n-1)
                substrRank[i].rightRank = ord(t[i+1]);
            substrRank[i].index = i;
        }
        sort(substrRank, substrRank+n, cmp);
        // for(int i = 0; i < n; i++) cout<<substrRank[i].leftRank<<' '<<substrRank[i].rightRank<<' '<<endl;
        int l = 2;
        while(l < n){
            makeRanks(substrRank, rank, n);
            for(int i = 0; i < n; i++) {
                substrRank[i].leftRank = rank[i];
                substrRank[i].rightRank = 0;
                if(i + l < n)
                    substrRank[i].rightRank = rank[i+l];
                substrRank[i].index = i;
            }
            sort(substrRank, substrRank + n, cmp);
            // for(int i = 0; i < n; i++) cout<<substrRank[i].leftRank<<' '<<substrRank[i].rightRank<<endl;
            l *= 2;
        }
        for(int i = 0; i < n; i++){
            suffixArray[i] = substrRank[i].index;
        }
        return suffixArray;
    }
    int *computeLCP(string t, int *SA, int n){
        int *rank, *LCP;
        rank = (int *)malloc(sizeof(int) * n);
        LCP = (int *)malloc(sizeof(int) * n);
        for(int i = 0; i < n; i++){
            rank[SA[i]] = i;
        }
        int l = 0;
        LCP[0] = 0;
        for(int i = 0; i < n; i++){
            if(rank[i] > 0){
                int j = SA[rank[i] - 1];
                int m = max(i, j);
                while((m + l < n) && t[i + l] == t[j + l])
                    l++;
                LCP[rank[i]] = l;
                if(l > 0)
                    l--;
            }
        }
        return LCP;

    }
    string longestDupSubstring(string s) {
        int *SA, *LCP;
        int n = s.length();
        SA = computeSuffixArray(s, n);
        LCP = computeLCP(s, SA, n);
        int maxlen = 0, index = -1;
        for(int i = 0; i < n; i++){
            if(maxlen < LCP[i]){
                maxlen = LCP[i];
                index = i;
            }
        }
        // for(int i = 0; i < n; i++) cout<<SA[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i < n; i++) cout<<LCP[i]<<" ";
        // cout<<endl;
        return (maxlen == 0) ? "" : s.substr(SA[index], maxlen); 
    }
};