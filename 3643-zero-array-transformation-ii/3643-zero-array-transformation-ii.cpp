class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(),s = 0,c = 0;
        vector<int>A(n + 1);

        for(int i = 0;i < n;i++)
        {
            while(s + A[i] < nums[i])
            {
                c++;
                if(c > queries.size())return -1;

                int l = queries[c - 1][0], r = queries[c - 1][1], value = queries[c - 1][2];
                if(r >= i)
                {
                    A[max(l, i)] += value;
                    if
                    (r + 1 < A.size())
                    {
                        A[r + 1] -= value;
                    }
                }
            }
            s += A[i];
        }
        return c;
    }
};
