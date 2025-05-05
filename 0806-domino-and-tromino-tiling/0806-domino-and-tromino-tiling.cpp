class Solution {
public:
int mod = 1e9 +7;
    int numTilings(int n) {
        if(n <= 1) 
        return 1;
        if(n == 2)
        return 2;
        if(n == 3)
        return 5;
        vector<int>A(n + 1,0);
        A[0] = 1,A[1] = 1,A[2] = 2,A[3] = 5;
        for(int i = 4; i <= n; i++) 
            A[i] = (A[i - 1] * 2 + long(A[i - 3])) % mod;
        
        return A[n];
    }
};