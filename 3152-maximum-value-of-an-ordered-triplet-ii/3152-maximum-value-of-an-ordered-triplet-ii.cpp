class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        long long res =0,maxi =0,maxi2 =0;
        for(int i=0;i<n;i++)
        {
            res = max(res,maxi2 * nums[i]);
            maxi2 = max(maxi2,maxi - nums[i]);
            maxi = max(maxi,static_cast<long long>(nums[i]));

        }
        return res;
    }
};