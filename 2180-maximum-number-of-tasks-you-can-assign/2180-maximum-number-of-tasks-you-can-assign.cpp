class Solution {
public:
    int maxTaskAssign(vector<int>& tasks,vector<int>& workers,int pills,int strength) {
        int n = tasks.size(),m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        auto check = [&](int mid) -> bool {
            int p = pills;
            multiset<int>A;
            for (int i = m - mid;i < m;++i) {
            A.insert(workers[i]);
            }
            for(int i = mid - 1;i >= 0;--i)
            {
                if(auto it = prev(A.end()); *it >= tasks[i])
                {
                A.erase(it);
                }
                else
                {
                    if(!p)
                    {
                        return false;
                    }
                    auto rep =A.lower_bound(tasks[i] - strength);
                    if(rep ==A.end())
                    {
                        return false;
                    }
                    --p;
                A.erase(rep);
                }
            }
            return true;
        };

        int l = 1, r = min(m, n), ans = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};