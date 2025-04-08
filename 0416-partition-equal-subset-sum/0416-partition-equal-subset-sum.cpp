class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i:nums)
        sum += i;

        if(sum%2!=0)
        return false;

        int tar = sum/2;
        vector<bool>A(tar+1,false);
        A[0] = true;
        for(int i:nums)
        {
            for(int j=tar;j>=i;j--)
            {
                A[j] = A[j] || A[j-i];
                if(A[tar])
                return true;
            }
        }
        return A[tar];
    }
};