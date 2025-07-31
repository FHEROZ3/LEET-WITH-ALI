class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>A;
        unordered_set<int>B;
        for(int i:arr)
        {
            unordered_set<int>C;
            C.insert(i);

            for(int j:B)
            {
                C.insert(i | j);
            }
            B = move(C);
            A.insert(B.begin(),B.end());
        }
        return A.size();
    }
};