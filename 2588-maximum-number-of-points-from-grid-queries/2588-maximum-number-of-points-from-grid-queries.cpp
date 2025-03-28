class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        vector<int> res(queries.size(),0);
        vector<pair<int,int>>A = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<pair<int,int>>B;
        for (int i = 0; i < queries.size(); i++)
        {
            B.push_back({queries[i], i});
        }
        sort(B.begin(),B.end());
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            minHeap;
        vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
        int c = 0;
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        for(auto [queryValue, queryIndex] : B)
        {
           
            while(!minHeap.empty() && minHeap.top().first < queryValue) {
                auto [cellValue, position] = minHeap.top();
                minHeap.pop();
                int currentRow = position.first, currentCol = position.second;
              
                c++;
                for(auto [rowOffset, colOffset] :A) {
                    int newRow = currentRow + rowOffset,
                        newCol = currentCol + colOffset;
                    if(newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                        newCol < colCount && !visited[newRow][newCol]) {
                        minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                     
                        visited[newRow][newCol] = true;
                    }
                }
            }
            res[queryIndex] = c;
        }
        return res;
    }
};