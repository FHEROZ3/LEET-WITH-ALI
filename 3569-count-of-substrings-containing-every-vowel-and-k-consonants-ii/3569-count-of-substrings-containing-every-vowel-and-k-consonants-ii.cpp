class Solution {
public:
    typedef long long ll;
    ll countOfSubstrings(string word, int k) {
        int n = word.length();
        int ans[5] = {0};
        int c = 0;
        int i = 0;
        int j = 0;
        ll res = 0;
        int lv = 0;

        while(j < n)
        {
            if(word[j] == 'a')
            ans[0]++;
            else if(word[j] == 'e')
            ans[1]++;
            else if(word[j] == 'i')
            ans[2]++;
            else if(word[j] == 'o')
            ans[3]++;
            else if(word[j] == 'u')
            ans[4]++;
            else
            {
                c++;
            }

            while(c > k)
            {
                lv = 0;
                if(word[i] == 'a')
                ans[0]--;
                else if(word[i] == 'e')
                ans[1]--;
                else if(word[i] == 'i')
                ans[2]--;
                else if(word[i] == 'o')
                ans[3]--;
                else if(word[i] == 'u')
                ans[4]--;
                else
                {
                    c--;
                }
                i++;
            }
            if(c == k)
            {
                bool flag = true;
                if(ans[0]==0||ans[1] == 0||ans[2] == 0||ans[3] == 0||ans[4]==0)
                {
                    flag = false;
                }

                if(flag)
                {
                    while(c==k&&i<=j)
                    {
                        if(word[i]=='a'&&ans[0]>1)
                        ans[0]--;
                        else if(word[i] == 'e' && ans[1] > 1)
                        ans[1]--;
                        else if(word[i] == 'i' && ans[2] > 1)
                        ans[2]--;
                        else if(word[i] == 'o' && ans[3] > 1)
                        ans[3]--;
                        else if(word[i] == 'u' && ans[4] > 1)
                        ans[4]--;
                        else
                        {
                            break;
                        }
                        i++;
                        lv++;
                    }
                    res += lv+1;
                }
            }
            j++;
        }
        return res;  
    }
};