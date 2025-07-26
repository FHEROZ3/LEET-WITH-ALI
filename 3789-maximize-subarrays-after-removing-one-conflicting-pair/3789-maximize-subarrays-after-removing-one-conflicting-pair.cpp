class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> A(n + 1, INT_MAX), B(n + 1, INT_MAX);
        for (const auto& pair : conflictingPairs) {
            int a = min(pair[0], pair[1]), b = max(pair[0], pair[1]);
            if (A[a] > b) {
                B[a] = A[a];
                A[a] = b;
            } 
            else if (B[a] > b) {
                B[a] = b;
            }
        }
        long long ans = 0;
        int ib1 = n, b2 = INT_MAX;
        vector<long long> C(n + 1, 0);
        for (int i = n; i >= 1; i--) {
            if (A[ib1] > A[i]) {
                b2 = min(b2, A[ib1]);
                ib1 = i;
            } else {
                b2 = min(b2, A[i]);
            }
            ans += min(A[ib1], n + 1) - i;
            C[ib1] +=min(min(b2,B[ib1]), n + 1) - min(A[ib1], n + 1);
        }
        return ans + *max_element(C.begin(),C.end());
    }
};