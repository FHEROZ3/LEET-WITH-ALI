class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int mini = k;
        int c=0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='W')
            {
                c++;
            }
        }
        mini = c;
        for(int i=k;i<n;i++)
        {
            if(blocks[i-k]=='W')
            {
                c--;
            }
            if(blocks[i]=='W')
            {
                c++;
            }
            mini = min(mini,c);
        }
        return mini;
        
    }
};