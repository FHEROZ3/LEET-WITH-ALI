class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(),n2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while(pos1 < n1 && nums1[pos1] < 0)
        {
            pos1++;
        }
        while(pos2 < n2 && nums2[pos2] < 0)
        {
            pos2++;
        }
        long long l = -1e10, r = 1e10;
        while(l <= r)
        {
            long long m = (l + r) / 2;
            long long c = 0;
            for(int i1 = 0, i2 = pos2 - 1; i1 < pos1 && i2 >= 0;) 
            {
                if(static_cast<long long>(nums1[i1]) * nums2[i2] > m)
                {
                    i1++;
                }
                else
                {
                    c += pos1 - i1;
                    i2--;
                }
            }
            for(int i1 = pos1, i2 = n2 - 1; i1 < n1 && i2 >= pos2;)
            {
                if(static_cast<long long>(nums1[i1]) * nums2[i2] > m)
                {
                    i2--;
                }
                else
                {
                    c += i2 - pos2 + 1;
                    i1++;
                }
            }
            for(int i1 = 0, i2 = pos2; i1 < pos1 && i2 < n2;)
            {
                if(static_cast<long long>(nums1[i1]) * nums2[i2] > m)
                {
                    i2++;
                }
                else
                {
                    c += n2 - i2;
                    i1++;
                }
            }
            for(int i1 = pos1, i2 = 0; i1 < n1 && i2 < pos2;)
            {
                if(static_cast<long long>(nums1[i1]) * nums2[i2] > m)
                {
                    i1++;
                }
                else
                {
                    c += n1 - i1;
                    i2++;
                }
            }
            if(c < k)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};