const int MOD = 1e9 + 7, MAXI = 1e4 + 10,
          MAX_P = 15;  
int c[MAXI + MAX_P][MAX_P + 1];
vector<int>A[MAXI]; 
int sieve[MAXI];     

class Solution {
public:
    Solution() {
        if(c[0][0])
        {
            return;
        }
        for(int i = 2;i < MAXI; i++)
        {
            if(sieve[i] == 0)
            {
                for(int j = i; j < MAXI; j += i)
                {
                    sieve[j] = i;
                }
            }
        }
        for(int i = 2; i < MAXI; i++)
        {
            int x = i;
            while(x > 1)
            {
                int p = sieve[x];
                int cnt = 0;
                while(x % p == 0)
                {
                    x /= p;
                    cnt++;
                }
            A[i].push_back(cnt);
            }
        }
        c[0][0] = 1;
        for(int i = 1; i < MAXI + MAX_P; i++)
        {
            c[i][0] = 1;
            for(int j = 1; j <= min(i, MAX_P); j++)
            {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }
    int idealArrays(int n, int maxValue)
    {
        long long ans = 0;
        for(int x = 1; x <= maxValue; x++)
        {
            long long mul = 1;
            for(int p :A[x])
            {
                mul = mul * c[n + p - 1][p] % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return ans;
    }
};