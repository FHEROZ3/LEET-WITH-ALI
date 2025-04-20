class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int tot =0;
        unordered_map<int,int>A;
        for(int i:answers)
        {
            A[i]++;
        }
        for(auto& i:A)
        {
            tot = tot + ceil((double)i.second/(i.first+1))*(i.first+1);
        }
        return tot;
        
    }
};