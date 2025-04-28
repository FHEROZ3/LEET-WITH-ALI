class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans=0,tot=0;
        for(int i=0,j=0;j<n;j++)
        {
            tot+= nums[j];
            while(i<=j && tot *(j-i+1)>=k)
            {
                tot-= nums[i];
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
};