class Solution {
public:
    long long coloredCells(int n) {
        long long int c =  1 + 2LL * (n - 1) * n;
        return c;
    }
};