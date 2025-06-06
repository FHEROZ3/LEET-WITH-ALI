class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> A;
        for(char c : s) {
            A[c]++;
        }
        stack<char>stk;
        string res;
        char mini = 'a';
        for(char c : s)
        {
            stk.emplace(c);
            A[c]--;
            while(mini != 'z' && A[mini] == 0)
            {
                mini++;
            }
            while(!stk.empty() && stk.top() <= mini)
            {
                res.push_back(stk.top());
                stk.pop();
            }
        }
        return res;
    }
};