class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
       map<pair<int,int>,int>A;
       int res=0;

       for(auto& i:dominoes)
       {
        int a = i[0],b=i[1];
        pair<int,int>key = a<b?make_pair(a,b):make_pair(b,a);
        res+=A[key];
        A[key]++;
       }
       return res;
    }
};