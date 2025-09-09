#include <cmath>

class Solution {
public:
    int minSensors(int n, int m, int k) {
        double s = 2*k + 1;
        return (int)(ceil(n / s) * ceil(m / s));
    }
};