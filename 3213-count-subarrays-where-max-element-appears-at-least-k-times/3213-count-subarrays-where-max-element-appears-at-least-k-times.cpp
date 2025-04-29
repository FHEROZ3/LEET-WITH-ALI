class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>A;
        long long ans = 0;
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] == maxi)
            {
            A.push_back(i);
            }
            int freq =A.size();
            if(freq >= k)
            {
                ans +=A[freq - k] + 1;
            }
        }
        return ans;
    }
};