class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>A;
        int n=nums.size();
        int r=0;
        unordered_set<int>B(nums.begin(),nums.end());
        int sizee = B.size();

        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                int rem = nums[i-1];
                A[rem]--;
                if(A[rem]==0)
                {
                    A.erase(rem);
                }
            }

    while(r<n && A.size()<sizee)
    {
        int add = nums[r];
        A[add]++;
        r++;
    }

    if(A.size()==sizee)
    {
        res += (n-r+1);
    }

        }
        return res;
    }
};