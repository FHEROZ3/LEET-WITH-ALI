class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            string a = to_string(nums[i]);
            int b = a.length();
            if(b%2==0)
            c++;
        }
        return c;
    }
};