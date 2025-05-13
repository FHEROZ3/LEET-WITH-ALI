class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>A;
        int sum=0,c=0;
        A[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            int r = sum-k;
            c+= A[r];
            A[sum]+=1;
        }
        return c;
    }
};