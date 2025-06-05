class Solution {
public:
    char dfs(unordered_map<char, vector<char>>& adj, char cur, vector<int>& A) {
        A[cur - 'a'] = 1;
        char mini = cur;
        for(char neighbor : adj[cur])
        {
            if(A[neighbor - 'a'] == 0) {
                mini = min(mini, dfs(adj, neighbor, A));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj;
        for(int i = 0; i < n; ++i)
        {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res;
        for(char ch : baseStr)
        {
            vector<int> A(26, 0);
            char mini = dfs(adj, ch, A);
            res.push_back(mini);
        }

        return res;
    }
};