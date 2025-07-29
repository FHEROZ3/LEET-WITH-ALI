class Solution {
public:
    int finddays(vector<int>&weights,int cap)
    {
        int days=1;
        int load=0;
        int n = weights.size();
        for(int i=0;i<n;i++)
        {
            if(load+weights[i]>cap)
            {
                days+=1;
                load = weights[i];
            }
            else
            {
                load+=weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);
        while(l<=h)
        {
            int mid = (l+h)/2;
            int val = finddays(weights,mid);
            if(val<=days)
            {
                h = mid -1;
            }
            else
            {
                l = mid +1;
            }
        } 
        return l;
    }
};