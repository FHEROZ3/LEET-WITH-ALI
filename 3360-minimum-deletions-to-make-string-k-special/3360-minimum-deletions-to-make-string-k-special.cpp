class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>A;
        for(auto &i : word)
        {
            A[i]++;
        }
        int res = word.size();
        for(auto &[ch1, freq1] : A)
        {
            int del = 0;
            for(auto &[ch2, freq2] : A)
            {
                if(freq1 >freq2)
                {
                    del += freq2;
                }
                else if(freq2> freq1 + k)
                {
                    del += freq2 - (freq1 + k);
                }
            }
            res = min(res, del);
        }
        return res;
    }
};