class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>A(n,false);
        vector<unordered_set<int>>B;

        for(int i = 0;i < n;i++)
        {
            if(!A[i]) {
                unordered_set<int>C = {i};
                bool flag = true;
                while(flag)
                {
                    flag = false;
                    for(auto i : edges) {
                        if(C.count(i[0]) && !C.count(i[1])) {
                            C.insert(i[1]);
                            flag = true;
                        }
                        if(C.count(i[1]) && !C.count(i[0]))
                        {
                            C.insert(i[0]);
                            flag = true;
                        }
                    }
                }
                for(int i : C)
                    A[i] = true;
                B.push_back(C);
            }
        }

        int cnt = 0;
        for(auto C : B)
        {
            int k = C.size();
            int expected = k * (k - 1) / 2;
            int act = 0;
            for(auto i : edges)
                if(C.count(i[0]) && C.count(i[1]))
                    act++;
            if(act == expected)
                cnt++;
        }

        return cnt;
    }
};