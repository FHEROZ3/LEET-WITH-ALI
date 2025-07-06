class FindSumPairs {
private:
    vector<int>A,B;
    unordered_map<int, int> cnt;

public:
    FindSumPairs(vector<int>& A, vector<int>& B) {
        this->A = A;
        this->B = B;
        for (int num : B) {
            ++cnt[num];
        }
    }
    void add(int index, int val) {
        --cnt[B[index]];
        B[index] += val;
        ++cnt[B[index]];
    }
    int count(int tot) {
        int ans = 0;
        for (int num : A) {
            int rest = tot - num;
            if (cnt.count(rest)) {
                ans += cnt[rest];
            }
        }
        return ans;
    }
};