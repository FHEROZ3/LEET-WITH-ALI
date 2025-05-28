class Solution {
public:
    int dfs(int node, int parent, const vector<vector<int>>& A, int k) {
        if(k < 0) {
            return 0;
        }
        int B = 1;
        for(int i : A[node])
        {
            if (i == parent) {
                continue;
            }
            B += dfs(i, node, A, k - 1);
        }
        return B;
    }
    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>>A(n);
        for(const auto& edge : edges)
        {
            A[edge[0]].push_back(edge[1]);
            A[edge[1]].push_back(edge[0]);
        }
        vector<int>B(n);
        for (int i = 0; i < n; i++)
        {
            B[i] = dfs(i, -1, A, k);
        }
        return B;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> count1 = build(edges1, k);
        vector<int> count2 = build(edges2, k - 1);
        int maxCount2 = *max_element(count2.begin(), count2.end());
        vector<int> B(n);
        for (int i = 0; i < n; i++) {
            B[i] = count1[i] + maxCount2;
        }
        return B;
    }
};