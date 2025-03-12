class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int  l=0,r=n-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(nums[m]>0)
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
            int p = n-l;
            l =0;
            r= n-1;
            while(l<=r)
            {
                int m = l+(r-l)/2;
                if(nums[m]<0)
                {
                    l = m+1;

                }
                else
                {
                    r = m-1;
                }
            }
         int ni = r+1;
                
            

        return max(p,ni);
    }
};