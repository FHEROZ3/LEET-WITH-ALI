class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res=-1,res1=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>res1)
            {
                res = max(res,nums[i]-res1);
            }
            else
            {
                res1 = nums[i];
            }
        }
        return res;
    }
};