class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>A;
        for(int i:nums)
        {
            if(i<k)
            {
                return -1;
            }
            else if(i>k)
            {
                A.insert(i);
            }
        }
        return A.size();
    }
};