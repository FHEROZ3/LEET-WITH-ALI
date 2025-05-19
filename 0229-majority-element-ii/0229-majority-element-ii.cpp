class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       int mini;
       int c1=0,c2=0,ele1 = INT_MIN,ele2 = INT_MIN;
       for(int i=0;i<n;i++)
       {
            if(c1==0 && nums[i]!=ele2)
            {
                c1=1;
                ele1 = nums[i];
            }
            else if(c2==0 && nums[i]!=ele1)
            {
                c2=1;
                ele2 = nums[i];
            }
            else if(nums[i]==ele1)
            {
                    c1++;
            }
            else if(nums[i]==ele2)
            {
                c2++;
            }
            else
            {
                c1--,c2--;
            }
       }
    int c11=0,c22=0;
       for(int i=0;i<n;i++)
       {
            if(nums[i]==ele1)
            c11++;
            if(nums[i]==ele2)
            c22++;
       }
        mini = int(n/3)+1;
        vector<int>A;
        if(c11>=mini)
        A.push_back(ele1);
        if(c22>=mini)
        A.push_back(ele2);
        return A;

    }
};