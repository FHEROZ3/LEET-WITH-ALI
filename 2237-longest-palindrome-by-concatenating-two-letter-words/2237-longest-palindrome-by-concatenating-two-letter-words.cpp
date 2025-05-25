class Solution {
public:
    int longestPalindrome(vector<string>& words, int c = 0) {
        vector<vector<int>>A(26, vector<int>(26, 0));
        int mid = 0;
        for(auto &s :words)
        {
            int x = s[0] - 'a', y = s[1] - 'a';
            if(A[y][x] > 0)
            {
                A[y][x]--;
                c += 4;
                if (x == y)
                mid--;
            }
            else
            {
                A[x][y]++;
                if (x == y)
                mid++;
            }
        }
        if(mid > 0)
        c += 2;
        return c;
    }
};