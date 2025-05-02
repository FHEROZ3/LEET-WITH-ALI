class Solution {
public:
    static string pushDominoes(string dominoes) {
        const int n = dominoes.size();
        vector<int>lf(n, 0),rf(n, 0);
        int force = 0;
        for(int i = 0; i < n; ++i){
            if(dominoes[i] == 'R')
            force = n;
            else if(dominoes[i] == 'L')
            force = 0;
            else force = max(force - 1, 0);
            rf[i] = force;
        }
        force = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(dominoes[i] == 'L')
            force = n;
            else if(dominoes[i] == 'R')
            force = 0;
            else force = max(force - 1, 0);
            lf[i] = force;
        }
        string res(n, '.');
        for(int i = 0; i < n; ++i)
        {
            if(rf[i] == lf[i])
                res[i] = '.';
            else if(rf[i] > lf[i])
                res[i] = 'R';
            else
                res[i] = 'L';
        }

        return res;
    }
};
