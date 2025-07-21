class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        int c=1;
        string res = "";
        res.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==prev)
            {
                c++;
            }
            else
            {
                prev = s[i];
                c=1;
            }
            if(c<3)
            res.push_back(s[i]);
        }
            return res;
    }
};