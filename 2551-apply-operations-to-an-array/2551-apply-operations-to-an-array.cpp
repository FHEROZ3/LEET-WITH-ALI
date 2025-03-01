class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1] =0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[c++]=nums[i];
            }
        }

        while(c<n)
        {
            nums[c++] =0;
        }
        return nums;
    }
};