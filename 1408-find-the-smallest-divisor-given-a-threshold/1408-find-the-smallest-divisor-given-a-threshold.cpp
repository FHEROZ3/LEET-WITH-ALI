class Solution {
public:
        int maxi(vector<int>&nums)
        {
            int res = INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>res)
                res = nums[i];
            }
            return res;
        }

     int thusu(vector<int>&nums,int a)
     {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + (nums[i]+a-1)/a;
        }
        return sum;
     }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l =1,h = maxi(nums);
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            int val = thusu(nums,mid);
            if(val<=threshold)
            {
                h = mid - 1;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};