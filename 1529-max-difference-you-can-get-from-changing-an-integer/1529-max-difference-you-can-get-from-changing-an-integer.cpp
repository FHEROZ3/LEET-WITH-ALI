class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char x, char y) {
            for(char& dig : s) {
                if(dig == x) {
                    dig = y;
                }
            }
        };

        string min_num = to_string(num);
        string max_num = to_string(num);
        for(char dig : max_num) {
            if(dig != '9') {
                replace(max_num, dig, '9');
                break;
            }
        }
        for(int i = 0; i < min_num.size(); ++i)
        {
            char dig = min_num[i];
            if(i == 0) {
                if(dig != '1') {
                    replace(min_num, dig, '1');
                    break;
                }
            }
            else{
                if(dig != '0' && dig != min_num[0])
                {
                    replace(min_num, dig, '0');
                    break;
                }
            }
        }
        return stoi(max_num) - stoi(min_num);
    }
};