class Solution {
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for(int i = 1;i < n;i++)
        {
            string temp = "";
            int c = 1;
            for(int j = 1; j < ans.size(); j++)
            {
                if(ans[j] == ans[j - 1])
                {
                    c++;
                }
                else
                {
                    temp += to_string(c) + ans[j - 1];
                    c = 1;
                }
            }
            temp += to_string(c) + ans.back();
            ans = temp;
        }
        return ans;
    }
};