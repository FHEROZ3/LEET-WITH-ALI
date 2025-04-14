class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c)
    {
        int ans = 0,n = arr.size();
        vector<int>A(1001,0);
        for(int j = 0; j < n;++j)
        {
            for(int k = j + 1; k < n;++k)
            {
                if(abs(arr[j] - arr[k]) <= b)
                {
                    int ma = arr[j] - a, rj = arr[j] + a;
                    int na = arr[k] - c, rk = arr[k] + c;
                    int l = max(0, max(ma, na)), r = min(1000, min(rj, rk));
                    if(l<=r)
                    {
                        if(l == 0)
                        {
                            ans += A[r];
                        }
                        else
                        {
                            ans += A[r] - A[l - 1];
                        }
                    }
                }
            }
            for(int k = arr[j];k <= 1000;++k) 
            {
                ++A[k];
            }
        }
        return ans;
    }
};