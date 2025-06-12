class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int diff=0;
        for(int i=0;i<n;i++)
        {
            int a = (i+1)%n;
             diff = max(abs(nums[i]-nums[a]),diff);
             
        }
        return diff;
    }
};