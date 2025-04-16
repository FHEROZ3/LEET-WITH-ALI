class Solution {
public:
    long long countGood(vector<int>& nums, int k)
    {
        int n = nums.size();
        int c = 0,d = -1;
        unordered_map<int,int>A;
        long long ans = 0;
        for(int i = 0;i < n;++i)
        {
            while(c < k && d + 1 < n)
            {
                ++d;
                c += A[nums[d]];
                ++A[nums[d]];
            }
            if(c >= k)
            {
                ans += n - d;
            }
            --A[nums[i]];
            c -= A[nums[i]];
        }
        return ans;
    }
};