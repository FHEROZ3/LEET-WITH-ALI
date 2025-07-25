class Solution {
public:

    void merge(vector<int>&arr,int low,int mid,int high)
    {
        vector<int>temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low;i<=high;i++)
        {
            arr[i] = temp[i-low];
        }
    }

    int countpairs(vector<int>&arr,int low,int mid,int high)
    {
        int right = mid+1;
        int c=0;
        for(int i=low;i<=mid;i++)
        {
            while(right<=high && (long long)arr[i]>2LL * arr[right])
            {
                right++;
            }
            c+= right - (mid+1);
        }
        return c;
    }

    int ms(vector<int>&arr,int low,int high)
    {
        int c=0;
        if(low>=high)
        return c;
        int mid = (low+high)/2;
        c+=  ms(arr,low,mid);
        c+= ms(arr,mid+1,high);
        c+= countpairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return c;
    }


    int reversePairs(vector<int>& nums) {
        int n = nums.size();
       return ms(nums,0,n-1);
    }

};