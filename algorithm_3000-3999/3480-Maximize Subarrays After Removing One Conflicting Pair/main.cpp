class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> lefts[n + 1];
        for (const auto& p : conflictingPairs) {
            int l = p[0], r = p[1];
            if (l > r) { std::swap(l, r); }
            lefts[r].push_back(l);
        }

        long long ret = 0;
        int lft1stMax = 0, lft2ndMax = 0;
        vector<long long> gains(n + 1, 0);
        for (int r = 1; r <= n; ++r) {
            for (int l : lefts[r]) {
                if (l > lft1stMax) {
                    lft2ndMax = lft1stMax;
                    lft1stMax = l;
                }
                else if (l > lft2ndMax) {
                    lft2ndMax = l;
                }
            }

            ret += r - lft1stMax;

            gains[lft1stMax] += lft1stMax - lft2ndMax;
        }

        return ret + *std::max_element(gains.begin(), gains.end());
    }
};
