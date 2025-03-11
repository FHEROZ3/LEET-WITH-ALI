class Solution {
public:
    int numberOfSubstrings(string s) {
        int c = 0;
        int l = 0;
        unordered_map<char, int>A = {{'a', 0},{'b', 0},{'c', 0}};
        
        for(int i = 0; i < s.length();++i)
        {
            A[s[i]]++;
            
            while(A['a'] > 0 && A['b'] > 0 && A['c'] > 0)
            {
                c += s.length() - i;
                A[s[l]]--;
                l++;
            }
        }
        
        return c;
    }
};