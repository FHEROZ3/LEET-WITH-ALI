class Solution {
public:
    vector<vector<int>> generate(int numRows)
     {
        vector<vector<int>>A;
        for(int i=0;i<numRows;i++)
        {
        vector<int>row;
        long long ans =1;
        row.push_back(ans);
        
        for(int j=1;j<=i;j++)
        {
            ans = ans*(i-j+1);
            ans = ans/j;
            row.push_back((int)ans);
        }
        A.push_back(row);

        
        }

        return A;
            
     }
};