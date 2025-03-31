class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int>A(n - 1,0);
        for(int i = 0; i < n - 1; ++i)
        {
        A[i] += weights[i] + weights[i + 1];
        }

        sort(A.begin(),A.end());
        long long ans = 0;
        for(int i = 0;i < k - 1;++i)
        {
            ans +=A[n - 2 - i] -A[i];
        }
        return ans;
    }
};