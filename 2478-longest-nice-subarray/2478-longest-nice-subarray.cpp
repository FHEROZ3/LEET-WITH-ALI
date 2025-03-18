class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int c = 1;
        int l = 0;
        int d = 0;
        
        for(int i = 0;i < n;i++)
        {
            while((d & nums[i]) != 0)
            {
                d ^= nums[l];
                l++;
            }
            
            d |= nums[i];
            c = max(c, i - l + 1);
        }
        
        return c;
    }
};