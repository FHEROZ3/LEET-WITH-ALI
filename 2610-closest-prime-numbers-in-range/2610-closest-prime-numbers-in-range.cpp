class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        auto is_prime = [](int n)
        {
            if(n <= 1) return false;
            if(n <= 3) return true;
            if(n % 2 == 0 || n % 3 == 0)
            return false;
            for(int i = 5; i * i <= n;i += 6)
            {
                if(n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        };

        vector<int>A;
        for(int num = max(2, left); num <= right; ++num) {
            if (is_prime(num)) {
                A.push_back(num);
            }
        }

        if(A.size() < 2) {
            return {-1, -1};
        }

        int mini = INT_MAX;
        vector<int> res = {-1, -1};

        for(int i = 1; i < A.size(); ++i) {
            int gap = A[i] - A[i - 1];
            if(gap < mini) {
                mini = gap;
            res = {A[i - 1], A[i]};
            }
        }

        return res;
    }
};