class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
            reverse(s.begin(), s.end());
        }

        int aCount = 0, bCount = 0, tot = 0;
        for (int i = 0; i < s.size(); ++i) {
            char curr = s[i];
            if (curr == 'a') {
                ++aCount;
            } else if (curr == 'b') {
                if (aCount > 0) {
           
                    --aCount;
                    tot += x;
                } else {
             
                    ++bCount;
                }
            } else {
                
                tot += min(bCount, aCount) * y;
               
                aCount = bCount = 0;
            }
        }
        tot += min(bCount, aCount) * y;
        return tot;
    }
};