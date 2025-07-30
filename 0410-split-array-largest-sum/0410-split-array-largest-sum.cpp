class Solution {
public:

    int count(vector<int>&nums,int maxi)
    {
        long long sum=0;
        int part=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]+sum<=maxi)
            {
                sum+=nums[i];
            }
            else
            {
                part++;
                sum = nums[i];
            }
        }
        return part;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);
        while(l<=h)
        {
            int mid = (l+h)/2;
            int val = count(nums,mid);
            if(val>k)
            {
                l = mid+1;
            }
            else
            {
                h = mid -1;
            }
        }
        return l;
    }
};