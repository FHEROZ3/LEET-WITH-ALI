class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>A,B;
        int n = nums.size();
        for(auto& num : nums) {
            B[num]++;
        }
        for(int index = 0;index < n;index++)
        {
            int num = nums[index];
            B[num]--;
            A[num]++;
            if(A[num] * 2 > index + 1 && B[num] * 2 > n - index - 1)
            {
                return index;
            }
        }
        return -1;
    }
};