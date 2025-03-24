class Solution {
    public:
        int countDays(int days, vector<vector<int>> &nums) {
            int A = 0,temp = 1;
            sort(nums.begin() ,nums.end()); 
            for(auto &i: nums)
            {
                A += max(0, i[0] - temp);
                temp = max(temp, i[1] + 1); 
                if(temp > days) 
                    break; 
            }
            return A + max(0,days - temp + 1);
        }
};