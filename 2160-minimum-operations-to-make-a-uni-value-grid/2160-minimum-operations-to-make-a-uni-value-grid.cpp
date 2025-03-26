class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>A;
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                A.push_back(grid[i][j]);
            }
        }

        int length = A.size();
        nth_element(A.begin(), A.begin() + length / 2,
                    A.end());

       
        int C = A[length / 2];

        for(int i : A)
        {
            
            if(i % x != C % x) 
            return -1;
           
            res += abs(C - i) / x;
        }

        return res;
    }
};