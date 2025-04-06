class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>A(nums.size(),1),B(nums.size(),-1);
        int maxi =0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && A[i]<A[j]+1)
                {
                    A[i] = A[j]+1;
                    B[i] = j;
                }
            }
            if(A[i]>A[maxi])
            {
                maxi = i;
            }
        }
        vector<int>res;
        for(int i=maxi;i>=0;i=B[i])
        {
            res.push_back(nums[i]);
            if(B[i]==-1)
            break;
        }
        return res;
    }
};