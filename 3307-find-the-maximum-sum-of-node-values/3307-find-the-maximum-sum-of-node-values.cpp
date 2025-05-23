class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,vector<vector<int>>& edges) {
        vector<int>A;
        long long c = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            A.push_back((nums[i] ^ k) - nums[i]);
            c += 1ll * nums[i];
        }
        sort(A.begin(), A.end(), greater<int>());
        for(int i = 0; i < A.size(); i += 2)
        {

            if(i + 1 == A.size())
            {
                break;
            }
            long long pairSum = A[i] + A[i + 1];
            if(pairSum > 0)
            {
                c += pairSum;
            }
        }
        return c;
    }
};