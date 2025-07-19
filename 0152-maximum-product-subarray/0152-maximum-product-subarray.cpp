class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0],maxi = nums[0],res = nums[0];
        for(int i=1;i<n;i++)
        {
            int prevmax = maxi;
            int prevmini = mini;
            maxi = max({nums[i],nums[i]*prevmax,nums[i]*prevmini});
            mini = min({nums[i],nums[i]*prevmax,nums[i]*prevmini});
            res = max(res,maxi);
        }
        return res;
        
    }
};