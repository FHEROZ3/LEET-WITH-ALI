class Solution {
public:
static constexpr int mod = 1000000007;
    int lengthAfterTransformations(string s, int t) {
        vector<int>A(26);
        for(char ch : s)
        {
            ++A[ch - 'a'];
        }
        for(int i = 0; i < t; ++i)
        {
            vector<int>B(26);
            B[0] = A[25];
            B[1] = (A[25] + A[0]) % mod;
            for(int i = 2; i < 26; ++i)
            {
                B[i] = A[i - 1];
            }
            A = move(B);
        }
        int ans = 0;
        for(int i = 0;i < 26;i++)
        {
            ans = (ans + A[i]) % mod;
        }
        return ans;
    }


    
};