class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n-2;i++)
        {
            int p = arr[i]*arr[i+1]*arr[i+2];
            if(p%2==1)
            return true;
        }
        return false;
    }
};