class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>A;
        for(int i=0;i<n;i++)
        {
            A.push_back(nums[nums[i]]);
        }
        return A;
    }
};