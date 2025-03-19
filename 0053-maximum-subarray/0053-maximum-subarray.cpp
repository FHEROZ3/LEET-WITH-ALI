class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int max = INT_MIN;
        int sum =0;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            sum =nums[i]+sum;
            if(sum>max)
            {
                max = sum;
            }
            if(sum<0)
            {
              sum =0;  
            }
        }
        return max;
    }
};