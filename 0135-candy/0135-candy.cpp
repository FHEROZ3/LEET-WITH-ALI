class Solution {
public:
    int candy(vector<int>& ratings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int l = ratings.size();
        int ans=0;
        vector<int>balu(l,1);
        for(int i=1;i<l;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                balu[i] = balu[i-1]+1;
            }
        }

        for(int i = l-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                balu[i] = max(balu[i],balu[i+1]+1);
            }
        }
        for(int i=0;i<l;i++)
        {
            ans = ans + balu[i];
        }
        return ans;
            
    }
};