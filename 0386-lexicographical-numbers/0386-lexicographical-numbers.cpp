class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>A;
        int a = 1;
        for(int i = 0; i < n; ++i)
        {
            A.push_back(a);
            if(a * 10 <= n)
            {
                a *= 10;
            }
            else
            {
                while(a % 10 == 9 || a >= n)
                {
                    a /= 10; 
                }
                a += 1; 
            }
        }
        return A;
    }
};