class Solution {
public:
    long long countSubstrings(string s) {
        std::function<long long(int)> f = [&](int k) {
            int counts[k];
            std::fill(counts, counts + k, 0);
            counts[0] = 1;

            int tmps[k];

            long long ret = 0;
            for (int i = 0, r = 0; i < s.size(); ++i) {
                for (int d = 0; d < k; ++d) {
                    tmps[d] = counts[d];
                    counts[d] = 0;
                }

                for (int d = 0; d < k; ++d) {
                    counts[d * 10 % k] += tmps[d];
                }
                r = (r * 10 + (s[i] - '0')) % k;

                if (s[i] == '0' + k) {
                    ret += counts[r];
                }
            
                counts[r] += 1;
            }

            return ret;
        };

        long long ret = 0;
        for (int k = 1; k <= 9; ++k) {
            ret += f(k);
        }

        return ret;
    }
};
