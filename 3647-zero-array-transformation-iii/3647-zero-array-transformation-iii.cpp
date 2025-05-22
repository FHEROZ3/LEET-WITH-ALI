class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),[](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        priority_queue<int>A;
        vector<int>B(nums.size() + 1,0);
        int c = 0;
        for(int i = 0, j = 0; i < nums.size(); ++i) {
            c += B[i];
            while(j < queries.size() && queries[j][0] == i)
            {
                A.push(queries[j][1]);
                ++j;
            }
            while(c < nums[i] && !A.empty() && A.top() >= i)
            {
                c += 1;
                B[A.top() + 1] -= 1;
                A.pop();
            }
            if(c < nums[i])
            {
                return -1;
            }
        }
        return A.size();
    }
};