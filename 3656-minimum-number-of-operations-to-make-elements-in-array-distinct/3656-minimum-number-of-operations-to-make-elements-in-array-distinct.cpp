class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       
        vector<int>A(105);
        for(int i=nums.size()-1;i>=0;--i)
        {
            A[nums[i]]++;
            if(A[nums[i]]>1)
            {
                return (i+3)/3;
            }
        }
    return 0;
  

    }
};