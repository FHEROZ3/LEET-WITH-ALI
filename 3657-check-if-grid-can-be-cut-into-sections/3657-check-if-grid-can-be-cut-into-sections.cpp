class Solution {
public:
    bool check(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int c = 0;
        int maxi = intervals[0][1];
        for(auto& i : intervals)
        {
            int s = i[0], e = i[1];
            if (maxi <= s) {
                c++;
            }
            maxi = max(maxi, e);
        }
        return c >= 2;
    }
    
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>A,B;
        
        for (auto& i : rectangles) {
            A.push_back({i[0], i[2]});
            B.push_back({i[1], i[3]});
        }
        
        return check(A) || check(B);
    }
};