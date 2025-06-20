class Solution {
public:
    int maxDistance(string s, int k) {
        int lat = 0, longi = 0, res = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            switch (s[i]) {
                case 'N':
                    lat++;
                    break;
                case 'S':
                    lat--;
                    break;
                case 'E':
                    longi++;
                    break;
                case 'W':
                    longi--;
                    break;
            }
            res = max(res, min(abs(lat) + abs(longi) + k * 2, i + 1));
        }
        return res;
    }
};