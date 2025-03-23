class Solution {
public:
    int countPaths(int n,vector<vector<int>>& roads)
    {
        vector<vector<pair<int,int>>>A(n);
        for (const auto& i : roads) {
            int u = i[0], v = i[1], time = i[2];
            A[u].emplace_back(v,time);
            A[v].emplace_back(u,time);
        }

        vector<long long>B(n,LLONG_MAX);
        vector<int>C(n, 0);

        B[0] = 0;
        C[0] = 1;

        priority_queue<pair<long long,int>,vector<pair<long long, int>>,greater<>>pq;
        pq.emplace(0, 0);

        const int MOD = 1e9 + 7;

        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > B[node]) 
            continue;

            for(const auto& [i, time] : A[node])
            {
                if(B[node] + time < B[i])
                {
                    B[i] = B[node] + time;
                    C[i] = C[node];
                    pq.emplace(B[i], i);
                }
                else if(B[node] + time == B[i])
                {
                    C[i] = (C[i] + C[node]) % MOD;
                }
            }
        }

        return C[n - 1];
    }
};