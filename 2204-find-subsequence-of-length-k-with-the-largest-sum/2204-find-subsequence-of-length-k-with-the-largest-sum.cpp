class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>A;
        for(int i=0;i<n;i++)
        {
            A.push_back({i,nums[i]});
        }
        sort(A.begin(),A.end(),[](auto &a, auto &b)
        {
            return (a.second>b.second);
            
        });

        A.resize(k);
        sort(A.begin(),A.end(),[](auto &a, auto &b)
        {
            return (a.first<b.first);
            
        });
        vector<int>B;
        for(auto i:A)
        {
            B.push_back(i.second);
        }
        return B;

    }
};