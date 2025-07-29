class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
       //NOO


        int n = nums.size();
        vector<int> A(31, -1);
        vector<int> B(n);
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < 31; ++bit) 
            {
                if (!(nums[i] & (1 << bit))) 
                {
                    if (A[bit] != -1) {
                        j = max(j, A[bit]);
                    }
                } 
                else
                 {
                    A[bit] = i;
                }
            }
            B[i] = j - i + 1;
        }
        return B;
    }
};