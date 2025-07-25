class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size();
        int l =0,h =n-1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(target==nums[mid])
            return true;
            //edge case for this problem remaining same as part -1
            if(nums[l]==nums[mid] && nums[mid]==nums[h])
            {
                l = l+1;
                h = h-1;
                continue;
            }
            if(nums[l]<=nums[mid])
            {
            if(nums[l]<=target && target<=nums[mid])
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
            }
            else
            {
                if(nums[mid]<=target && target<=nums[h])
                {
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
        }
        return false;
    }
};