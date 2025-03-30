class Solution {
public:
    vector<int> partitionLabels(string s) {
            unordered_map<char,int>A;
            vector<int>res;
            int st=0,e=0;
            for(int i=0;i<s.size();i++)
            {
                A[s[i]]=i;
            }
            for(int i=0;i<s.size();i++)
            {
                e = max(e,A[s[i]]);
                if(i==e)
                {
                    res.push_back(e-st+1);
                    st = i+1;
                }
            }
            return res;
            
    }
};