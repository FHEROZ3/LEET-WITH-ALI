class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>A;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            if(i==0 || groups[i]!=groups[i-1])
            {
                A.emplace_back(words[i]);
            }
        }
        return A;

    }
};