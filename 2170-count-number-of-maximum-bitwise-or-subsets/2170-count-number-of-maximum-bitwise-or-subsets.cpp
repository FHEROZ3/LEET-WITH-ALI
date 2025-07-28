class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //NOO
        int maxi = 0;
        for (int num : nums)
        {
            maxi |= num;
        }
        int totalSubsets = 1 << nums.size(); 
        int subsetsWithMaxOr = 0;
        for (int subsetMask = 0; subsetMask < totalSubsets; subsetMask++)
        {
            int currentOrValue = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (((subsetMask >> i) & 1) == 1) {
                    currentOrValue |= nums[i];
                }
            }
            if (currentOrValue == maxi) {
                subsetsWithMaxOr++;
            }
        }
        return subsetsWithMaxOr;
    }
};