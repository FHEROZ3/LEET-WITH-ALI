#include <vector>
using namespace std;

class Solution {
public:
    vector<int>A,B;
    int findRoot(int node){
        if(A[node] != node)
        {
            A[node] = findRoot(A[node]);
        }
        return A[node];
    }

    vector<int>minimumCost(int n,vector<vector<int>>& edges,vector<vector<int>>& queries) {
        A.resize(n);
        B.assign(n, -1);
        for(int i = 0; i < n; i++) A[i] = i;

        for(auto& i : edges)
        {
            int source = i[0], target = i[1], weight = i[2];
            int sourceRoot = findRoot(source);
            int targetRoot = findRoot(target);

            if(B[sourceRoot] == -1) 
            B[sourceRoot] = weight;
            else 
            B[sourceRoot] &= weight;

            if(B[targetRoot] == -1) 
            B[targetRoot] = weight;
            else 
            B[targetRoot] &= weight;

            if(sourceRoot != targetRoot)
            {
                A[sourceRoot] = targetRoot;
                B[targetRoot] &= B[sourceRoot];
            }
        }

        vector<int>C;
        for(auto& q : queries)
        {
            int start = q[0], end = q[1];

            if(start == end) 
            C.push_back(0);
            else if (findRoot(start) != findRoot(end)) 
            C.push_back(-1);
            else 
            C.push_back(B[findRoot(start)]);
        }

        return C;
    }
};