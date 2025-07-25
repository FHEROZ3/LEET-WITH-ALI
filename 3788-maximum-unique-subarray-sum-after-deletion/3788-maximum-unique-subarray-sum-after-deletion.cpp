class Solution {
public:
    int maxSum(vector<int>& nums) {
       bool neg = true;
       int maxi = INT_MIN;
       for(int i:nums)
       {
        if(i>=0){
            neg = false;
        }
        if(i>maxi)
        {
            maxi = i;
        }
       }
        if(neg)
        return maxi;
        unordered_set<int>A(nums.begin(),nums.end());
        int sum=0;
        for(int val:A)
        {
            if(val>0)
            sum+=val;
        }
        return sum;
       
    }
};
