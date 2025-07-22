class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int csum=0,maxi=0;
        int l=0;
        unordered_set<int>A;
        for(int r=0;r<n;r++)
        {
            while(A.find(nums[r])!=A.end())
            {
                csum-= nums[l];
                A.erase(nums[l]);
                l++;
            }
            csum += nums[r];
            A.insert(nums[r]);
            maxi = max(csum,maxi);
        } 
        return maxi;
    }
};