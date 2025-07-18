class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;

        vector<long long>A(n),B(n);
        priority_queue<int>maxi;
        priority_queue<int,vector<int>,greater<int>>mini;
        long long lsum =0,rsum=0,diff=LLONG_MAX;

        for(int i=0;i<k;i++)
        {
            maxi.push(nums[i]);
            lsum+= nums[i];
        }
        A[k-1] = lsum;

        for(int i=k;i<n-k;i++)
        {
            if(!maxi.empty() && nums[i]<maxi.top())
            {
                lsum = lsum + nums[i] - maxi.top();
                maxi.pop();
                maxi.push(nums[i]);
            }
            A[i] = lsum;
        }

        for(int i = n - 1; i >= n - k; --i)
        {
            mini.push(nums[i]);
            rsum += nums[i];
        }
        B[n - k] = rsum;

        for(int i = n - k - 1; i >= k - 1; --i)
        {
            if(!mini.empty() && nums[i] > mini.top())
            {
                rsum += nums[i] - mini.top();
                mini.pop();
                mini.push(nums[i]);
            }
            B[i] = rsum;
        }

        for(int i =k-1;i<n-k;i++)
        {
            diff = min(diff,A[i]-B[i+1]);
        }
        return diff;


    }
};