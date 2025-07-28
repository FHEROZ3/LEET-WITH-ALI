class Solution {
public:

    bool possible(vector<int>&bloomDay,int day,int m,int k)
    {
        int n = bloomDay.size();
        int c=0;
        int tot=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=day)
            {
                c++;
            }
            else
            {
                tot+=(c/k);
                c=0;
            }
        }
        tot+=(c/k);
        return tot>=m;

    }



    int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size(); 
    if(val > n)
    return -1; 
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        mini = min(mini,bloomDay[i]);
        maxi = max(maxi,bloomDay[i]);
    }
    int l = mini,h = maxi;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(possible(bloomDay, mid, m, k))
        {
            h = mid - 1;
        }
        else
        l = mid + 1;
    }
    return l;
}

    
};