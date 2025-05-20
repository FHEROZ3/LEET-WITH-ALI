class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>A(nums.size()+1,0);
        for(const auto& i:queries)
        {
            A[i[0]]++;
            if(i[1]+1 < nums.size())
            A[i[1]+1]--;
        }

        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            c+= A[i];
            if(nums[i]>c)
            return false;
        }
        return true;

    }
};