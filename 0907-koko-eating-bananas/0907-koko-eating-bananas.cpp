class Solution {
public:

    long long hours(vector<int>&piles,int mid)
    {
        long long tot=0;
        for(int i=0;i<piles.size();i++)
        {
            tot+= ceil((double)piles[i]/(double)mid);
        }
        return tot;
    }


    int minEatingSpeed(vector<int>& piles,int hour) {
        int l = 1,h = *max_element(piles.begin(), piles.end());;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            long long cal = hours(piles,mid);
            if(cal<=hour)
            {
                h = mid-1; 
            }
            else
            {
                l = mid+1;
            }
            
        }
        return l;
    }
};