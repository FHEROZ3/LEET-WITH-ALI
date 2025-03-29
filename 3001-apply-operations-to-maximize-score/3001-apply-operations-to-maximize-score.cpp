class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>A(n,0);
        int c = 0;
        for(int i = 0;i < n;i++)
        {
            c = max(c,nums[i]);
        }
        vector<int> C = getPrimes(c);
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            for(int prime : C) {
                if(prime * prime > num)
                    break;  
                if(num % prime != 0)
                    continue;

                A[i]++;  
                while(num % prime == 0)
                    num /= prime;  
            }
            if(num > 1) 
            A[i]++;
        }
        vector<int>nextDominant(n, n);
        vector<int>prevDominant(n, -1);
        stack<int>F;
        for(int i = 0; i < n; i++)
        {
           
            while(!F.empty() && A[F.top()] <A[i])
            {
                int topIndex = F.top();
                F.pop();
                nextDominant[topIndex] = i;
            }
            if(!F.empty())
                prevDominant[i] = F.top();
            F.push(i);
        }
        vector<long long> numOfSubarrays(n);
        for(int i = 0; i < n; i++) {
            numOfSubarrays[i] = (long long)(nextDominant[i] - i) *
                                    (i - prevDominant[i]);
        }
        vector<pair<int, int>> sortedArray(n);
        for (int i = 0; i < n; i++) {
            sortedArray[i] = {nums[i], i};
        }
        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int processingIndex = 0;
        while(k > 0)
        {
            auto [num, i] = sortedArray[processingIndex++];
            long long operations = min((long long)k, numOfSubarrays[i]);
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }
        return score;
    }

private:
    long long power(long long base, long long ee) {
        long long res = 1;
        while(ee > 0)
        {
            if(ee % 2 == 1)
            {
                res = ((res * base) % MOD);
            }
            base = (base * base) % MOD;
            ee /= 2;
        }

        return res;
    }
    vector<int> getPrimes(int limit) {
        vector<bool>B(limit + 1,true);
        vector<int>C;
        for(int i = 2;i <= limit;i++) {
            if(!B[i])
            continue;
            C.push_back(i);
            for(long long multiple = (long long)i * i;
                 multiple <= limit; multiple += i) {
                B[multiple] = false;
            }
        }

        return C;
    }
};