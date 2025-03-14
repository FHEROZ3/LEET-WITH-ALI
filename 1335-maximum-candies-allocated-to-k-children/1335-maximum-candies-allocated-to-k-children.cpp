class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1, r = *max_element(candies.begin(), candies.end());
        int res = 0;
        while(l <= r)
        {
            long long m = l + (r - l) / 2;
            long long c = 0;

            for(int i : candies)
            {
                c += i / m;
            }

            if(c >= k)
            {
                res = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return res;
    }
};