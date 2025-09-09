#define ll long long
#define ull unsigned long long
class Solution {
public:
    int get_msbll(long long x){
        return x ? 63 - __builtin_clzll(x) : -1;
    }
    // int count_remaining_rec(long long n, ull curr, int l, int r){
    //     if(r > l || curr > n){
    //         if(curr <= n){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     return count_remaining_rec(n, curr, l - 1, r + 1) + \
    //             count_remaining_rec(n, (curr | (1ULL << l) | (1ULL << r)), l - 1, r + 1);
    // }
    ll count_remaining(ull n, int L) {
        int half = (L + 1) / 2;
        ull start = 1ULL << (half - 1);
        ull end   = 1ULL << half;
        ull prefix = n >> (L / 2);
        ull pal, tmp = prefix;
        // odd length removing middle element
        if(L % 2){
            half--;
            tmp >>= 1;
        }
        ull rev = 0;
        for(int i = 0; i < half; i++){
            rev = (rev << 1) | (tmp & 1ULL);
            tmp >>= 1;
        }
        pal = (prefix << half) | rev;

        // count valid palindromes
        ll cnt = 0;
        if (prefix >= start) {
            cnt = (prefix - start);
            if (pal <= n) cnt += 1;
        }
        return cnt;
    }

    int countBinaryPalindromes(long long n) {
        if(n == 0) return 1;
        int msb = get_msbll(n);
        int k = 0;
        int total = 0;
        while(k < msb){
            int count = 1;
            // 2^(k / 2)
            count = 1 << (k / 2);
            total += count;
            k++;
        }
        // cout<< msb <<endl;
        // ull curr = (1ULL << msb) | 1ULL;
        // int rem_count = 0;
        // if(k % 2) rem_count = count_remaining(n, curr, msb - 1, 1);
        // else rem_count = count_remaining(n, curr, msb - 1, 1);
        // int rem_count = count_remaining(n, curr, msb - 1, 1);
        int L = msb + 1;
        ll rem_count = count_remaining(n, L);
        total += rem_count;
        return total + 1;
    }
};