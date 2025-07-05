class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>A;
        for(int i:arr)
        {
            A[i]++;
        }
        int c=-1;
        for(auto&[a,b]:A)
        {
            if(a==b)
            {
                c = max(c,a);
            }
        }
        return c;
    }
};