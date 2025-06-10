class Solution {
public:
    int maxDifference(string s) {
       unordered_map<char,int>A;
       for(char c:s)
       {
        A[c]++;
       }
       int odd=1,even=s.size();
       for(auto const& i:A)
       {
        int val = i.second;
        if(val%2==1)
        {
            odd = max(odd,val);
        }
        else
        {
            even = min(even,val);
        }
       }
       return odd-even;

    }
};