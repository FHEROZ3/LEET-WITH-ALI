class Solution {
private:
    int digits[100];

public:
    long long kMirror(int k, int n) {
        auto isKBasePalindrome = [&](long long x) -> bool {
            int length = -1;
            while(x)
            {
                digits[++length] = x % k;
                x /= k;
            }
            for(int i = 0, j = length; i < j; ++i, --j)
            {
                if(digits[i] != digits[j])
                {
                    return false;
                }
            }
            return true;
        };
        int s = 1;         
        int c = 0;         
        long long sum = 0;     
        while(c < n)
        {
            int end = s * 10; 
            for(int op = 0; op < 2; ++op)
            {
                for(int num = s; num < end && c < n; ++num)
                {
                    long long palindrome = num;
                    int mirrorPart = (op == 0) ? num / 10 : num;
                    while(mirrorPart)
                    {
                        palindrome = palindrome * 10 + (mirrorPart % 10);
                        mirrorPart /= 10;
                    }
                    if(isKBasePalindrome(palindrome))
                    {
                        sum += palindrome;
                        ++c;
                    }
                }
            }
            s = end;
        }
        return sum;
    }
};
