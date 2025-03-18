class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int l = nums.size();
        int c=0,ele;
        for(int i=0;i<l;i++)
        {
            if(c==0)
            {
                ele = nums[i];
                c=1;
            }
            else if(ele==nums[i])
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        int c1=0;
        for(auto const i:nums)
        {
            if(ele==i)
            c1++;
        }
        if(c1>(l/2))
        return ele;

        return 0;
    }
};