class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(),n = str2.length();
        vector<vector<int>>lcs(m + 1,vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                }
                else 
                {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        string res = "";
        
        while(i > 0 && j > 0)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                res += str1[i - 1];
                i--, j--;
            }
            else if(lcs[i - 1][j] > lcs[i][j - 1]) {
                res += str1[i - 1];
                i--;
            }
            else
            {
                res += str2[j - 1];
                j--;
            }
        }
        while(i > 0)
        res+= str1[--i];
        while(j > 0) 
        res += str2[--j];

        reverse(res.begin(), res.end());
        return res;
    }
};