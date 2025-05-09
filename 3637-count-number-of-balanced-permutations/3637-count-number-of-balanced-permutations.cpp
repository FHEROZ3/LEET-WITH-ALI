class Solution {
public:
    constexpr static long long M = 1e9 + 7;
    int countBalancedPermutations(string s) {
        int t = 0, n = s.size();
        vector<int> c(10);
        for (char ch : s) {
            int d = ch - '0';
            c[d]++;
            t += d;
        }
        if(t % 2)
        return 0;
        int h = t / 2;
        int mo = (n + 1) / 2;
        vector<vector<long long>>C(mo + 1,vector<long long>(mo + 1));
        vector<vector<long long>>f(h + 1,vector<long long>(mo + 1));
        for(int i = 0; i <= mo; i++)
        {
            C[i][i] = C[i][0] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
            }
        }
        f[0][0] = 1;
        int ps = 0, ts = 0;
        for(int i = 0; i <= 9; i++)
        {
            ps += c[i];
            ts += i * c[i];
            for(int o = min(ps, mo); o >= max(0, ps - (n - mo)); o--)
            {
                int e = ps - o;
                for(int curr = min(ts, h); curr >= max(0, ts - h); curr--)
                {
                    long long r = 0;
                    for(int j = max(0, c[i] - e); j <= min(c[i], o) && i * j <= curr; j++) {
                        long long w = C[o][j] * C[e][c[i] - j] % M;
                        r = (r + w * f[curr - i * j][o - j] % M) % M;
                    }
                    f[curr][o] = r % M;
                }
            }
        }
        return f[h][mo];
    }
};
