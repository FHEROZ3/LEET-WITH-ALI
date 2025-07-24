class Solution {
public:
    int calc(int part1, int part2, int part3)
    {
        return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
    }
    int minimumScore(vector<int>& nums,vector<vector<int>>& edges)
    {
        int n = nums.size(), cnt = 0;
        vector<int> A(n),B(n),C(n);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        function<void(int, int)> dfs = [&](int x, int fa) {
            B[x] = cnt++;
            A[x] = nums[x];
            for (auto& y : adj[x]) {
                if (y == fa) {
                    continue;
                }
                dfs(y, x);
                A[x] ^= A[y];
            }
            C[x] = cnt;
        };
        dfs(0, -1);
        int res = INT_MAX;
        for (int u = 1;u < n;u++) {
            for (int v = u + 1;v < n;v++) {
                if (B[v] > B[u] && B[v] < C[u])
                {
                    res = min(res,calc(A[0] ^ A[u], A[u] ^ A[v], A[v]));
                } else if (B[u] > B[v] && B[u] < C[v]) {
                    res = min(res,calc(A[0] ^ A[v], A[v] ^ A[u], A[u]));
                } else {
                    res = min(res,calc(A[0] ^ A[u] ^ A[v], A[u], A[v]));
                }
            }
        }
        return res;
    }
};