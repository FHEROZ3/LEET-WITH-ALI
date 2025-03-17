class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>A;
        for(int i:nums)
        {
            A[i]++;
        }
        for(auto i:A)
        {
            if(i.second % 2 !=0)
            {
                return false;
            }
        }
        return true;
    }
};