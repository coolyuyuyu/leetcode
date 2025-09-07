class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        std::function<long long(int)> f = [](int num) {
            int base = 1;
            long long ret = 0;
            for (int i = 0, base = 1; base <= num; ++i, base *= 2) {
                ret += 1LL * (i / 2 + 1) * (min(base * 2 - 1, num) - base + 1);
            }
            return ret;
        };

        long long ret = 0;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            ret += (f(r) - f(l - 1) + 1) / 2;
        }

        return ret;
    }
};
