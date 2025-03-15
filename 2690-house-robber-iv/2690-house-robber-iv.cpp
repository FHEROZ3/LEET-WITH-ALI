class Solution {
public:
    bool canRob(vector<int>& nums, int m,int k)
    {
        int c = 0,n = nums.size();
        for(int i = 0;i < n;i++)
        {
            if(nums[i]<= m)
            {
                c++;
                i++;
            }
        }
        return 
        c >= k;
    }

    int minCapability(vector<int>& nums,int k)
    {
        int l = 1, r = *max_element(nums.begin(),nums.end()),ans = r;
        while(l <= r)
        {
            int m = (l + r) / 2;
            if(canRob(nums,m,k))
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};
