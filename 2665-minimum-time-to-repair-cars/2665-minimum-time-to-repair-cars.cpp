#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1,r = 1e14,res = 0;
        while(l <= r)
        {
            ll m = l+(r-l) / 2;
             ll c = 0;
            for(int i : ranks)
            {
                c += sqrt(m / i);
                if(c >= cars) 
                break;
            }
            if(c >= cars)
            {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};