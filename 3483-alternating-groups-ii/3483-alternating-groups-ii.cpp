class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
         int n = colors.size();
        int c = 0;
        int l = 0;
        
        for(int i = 0;i < n + k - 1;++i)
        {
            if(i > 0 && colors[i % n] == colors[(i - 1) % n])
            {
                l = i;  
            }
            
            if(i - l + 1 >= k)
            {
                c++;  
            }
        }
        
        return c;
    }
};