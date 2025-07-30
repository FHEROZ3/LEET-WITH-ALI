class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi =0,cs=0,res=0;
        for(int i:nums)
        {
            if(i>maxi)
            {
                maxi = i;
                res = cs =0;
            }
            if(maxi==i)
            {
                cs++;
            }
            else
            {
                cs=0;
            }
            res = max(cs,res);
        }
        return res;
    }
};