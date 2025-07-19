class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>A;
        A.push_back(folder[0]);
        for(int i = 1;i < folder.size();i++)
        {
            string lf = A.back();
            lf += '/';
            if(folder[i].compare(0, lf.size(), lf) != 0) {
                A.push_back(folder[i]);
            }
        }
        return A;
    }
};