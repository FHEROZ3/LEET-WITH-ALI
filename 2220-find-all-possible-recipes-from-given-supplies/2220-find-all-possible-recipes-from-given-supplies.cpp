class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>available_supplies(supplies.begin(), supplies.end());
        unordered_map<string,vector<string>>A;
        unordered_map<string,int>B;
        unordered_map<string,vector<string>>C;
        for(int i = 0;i < recipes.size();i++)
        {
            string rec = recipes[i];
            C[rec] = ingredients[i];
            B[rec] = ingredients[i].size();

            for(const string& i : ingredients[i])
            {
                A[i].push_back(rec);
            }
        }

        queue<string>q;
        for(const string& i : supplies)
        {
            q.push(i);
        }

        vector<string>res;
        while(!q.empty())
        {
            string current = q.front();
            q.pop();
            if(C.find(current) != C.end())
            {
                res.push_back(current);
            }

            if(A.find(current) != A.end())
            {
                for(const string& i : A[current]){

                    B[i]--;
                    if(B[i] == 0){

                        q.push(i);
                    }
                }
            }
        }

        return res;
    }
};