class Solution {
public:
    vector<int>twoSum(vector<int>& arr,int target)
    {
        unordered_map<int,int>A;  
        for(int i = 0; i < arr.size(); i++)
        {
            int c = target - arr[i];

            if(A.find(c) != A.end())
            {
                return {A[c],i}; 
            }

            A[arr[i]] = i;
        }
        return {}; 
    }
};
