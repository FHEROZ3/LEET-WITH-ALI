class Solution {
public:
    int removeDuplicates(vector<int>& nums)
     {
       int l = nums.size();
        int b =1;
        for(int a=1;a<l;a++)
        {
            if(nums[a]!=nums[a-1])
            {
                nums[b] = nums[a];
                b++;
            }
        } 
        return b;
    }
};