class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long a = 0, b = 0;
        for(int i : nums1) {
            sum1 += i;
            if(i == 0)
            {
                sum1++;
                a++;
            }
        }
        for(int i : nums2)
        {
            sum2 += i;
            if(i == 0)
            {
                sum2++;
                b++;
            }
        }
        if(!a && sum2 > sum1 || !b && sum1 > sum2)
        {
            return -1;
        }
        return max(sum1,sum2);
    }
};