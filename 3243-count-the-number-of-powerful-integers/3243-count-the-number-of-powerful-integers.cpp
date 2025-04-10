class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,string s) {
        string start_ = to_string(start - 1), finish_ = to_string(finish);
        return calculate(finish_, s, limit) - calculate(start_, s, limit);
    }

    long long calculate(string x, string s, int limit)
    {
        if(x.length() < s.length())
        {
            return 0;
        }
        if(x.length() == s.length())
        {
            return x >= s ? 1 : 0;
        }

        string suf = x.substr(x.length() - s.length(), s.length());
        long long c = 0;
        int len = x.length() - s.length();

        for(int i = 0; i < len; i++)
        {
            if(limit < (x[i] - '0'))
            {
                c += (long)pow(limit + 1, len - i);
                return c;
            }
            c += (long)(x[i] - '0') * (long)pow(limit + 1, len - 1 - i);
        }
        if(suf >= s)
        {
            c++;
        }
        return c;
    }
};