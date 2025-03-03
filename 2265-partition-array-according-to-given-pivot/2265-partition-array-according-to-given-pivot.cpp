

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int>a,b,c;

        for (int num : nums)
        {
            if(num < pivot)
            {
                a.push_back(num);
            }
            else if(num == pivot) {
                b.push_back(num);
            }
            else
            {
                c.push_back(num);
            }
        }
        
        vector<int>A;
        A.insert(A.end(), a.begin(), a.end());
        A.insert(A.end(), b.begin(), b.end());
        A.insert(A.end(), c.begin(), c.end());
        
        return A;
    }
};
   
