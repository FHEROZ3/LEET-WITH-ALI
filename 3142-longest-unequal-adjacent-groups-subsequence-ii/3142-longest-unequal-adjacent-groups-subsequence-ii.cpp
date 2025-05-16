class Solution {
public:
    bool differByOneChar(string word1, string word2) {
        if(word1.length()!= word2.length())
        return false;
        int coutt = 0;
        for(int i = 0;i < word1.length();i++) 
            coutt += word1[i] != word2[i];
        return coutt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int>A(n,1),parent(n,-1);
        int maxi = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(groups[i] != groups[j] &&  differByOneChar(words[i], words[j]) && A[i] < A[j] + 1)
                { A[i] = A[j] + 1;
                    parent[i] = j;
                }
            }
            maxi = max(maxi,A[i]);
        }
        vector<string>res;
        for(int i = 0;i <n;i++)
        {
            if(maxi == A[i]) {
                while(i != -1) {
                    res.push_back(words[i]);
                    i = parent[i];
                }
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};