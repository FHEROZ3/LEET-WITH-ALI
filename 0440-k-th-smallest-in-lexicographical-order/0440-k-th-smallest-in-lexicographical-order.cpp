class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--; 
        while(k > 0)
        {
            long steps = 0;
            long f = curr, l = curr;
            while (f <= n)
            {
                steps += min(n + 1L, l + 1) - f;
                f *= 10;
                l = l * 10 + 9;
            }
            if(steps <= k)
            {
                curr += 1;
                k -= steps;
            }
            else{
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
