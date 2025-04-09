class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;
       int c=0,maxi =1;
       unordered_set<int>A;
       for(int i=0;i<n;i++)
       {
        A.insert(nums[i]);
       }
       for(auto i:A)
       {
        if(A.find(i-1)==A.end())
        {
            int c=1;
            int a = i;
            while(A.find(a+1)!=A.end())
            {
                a = a+1;
                c = c+1;

            }
            maxi = max(maxi,c);
        }
       }
       return maxi;
    }
};