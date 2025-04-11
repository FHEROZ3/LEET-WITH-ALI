class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++)
        {
            string ans;
            ans = to_string(i);
            int n = ans.length();
            if(n%2!=0)
            continue;
            int half = n/2;
            int lsum=0,rsum=0;
            for(int i=0;i<half;i++)
            {
                lsum += ans[i]-'0';
            }
            for(int i=half;i<n;i++)
            {
                rsum += ans[i]-'0';
            }
            if(lsum ==rsum)
            {
                c++;
            }
               
            
        }
        return c;
    }
};