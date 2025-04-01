class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>A(questions.size(),0);
        for(int i = questions.size() - 1;i >= 0;i--)
        {
            int index = i + questions[i][1] + 1;
            if(index < questions.size())
            {
            A[i] =A[index] + questions[i][0];
            }
            else
            {
            A[i] = questions[i][0];
            }
            if(i < questions.size() - 1) {
            A[i] = max(A[i + 1],A[i]);
            }
        }
        return A[0];
    }
};