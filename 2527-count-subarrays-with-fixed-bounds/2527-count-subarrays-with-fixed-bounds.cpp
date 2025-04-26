class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        long c=0,st = -1,mini = -1,maxi =-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mink || nums[i]>maxk)
            st = i;
            if(nums[i]==maxk)
                maxi = i;
            if(nums[i]==mink)
            mini = i;
            int valid = max(0L,min(mini,maxi)-st);
            c+= valid;
        }
        return c;
    }
};