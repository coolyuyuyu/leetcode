class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m = paths.size();

        typedef unsigned long long ULL;
        ULL base1 = 1e5 + 0;
        ULL base2 = 1e5 + 3;
        std::function<bool(int)> checkCommonSubpath = [&](int len) {
            ULL power1 = 1, power2 = 1;
            for (int i = 1; i < len; ++i) {
                power1 *= base1;
                power2 *= base2;
            }

            map<pair<ULL, ULL>, int> hashCnts;
            for (const auto& path : paths) {
                set<pair<ULL, ULL>> hashs;
                ULL hash1 = 0, hash2 = 0;
                for (int i = 0; i < path.size(); ++i) {
                    if (len <= i) {
                        hash1 -= path[i - len] * power1;
                        hash2 -= path[i - len] * power2;
                    }
                    hash1 = hash1 * base1 + path[i];
                    hash2 = hash2 * base2 + path[i];
                    if (len - 1 <= i && hashs.emplace(hash1, hash2).second) {
                        if (++hashCnts[{hash1, hash2}] == m) {
                            return true;
                        }
                    }
                }
            }

            return false;
        };

        int lo = 0, hi = INT_MAX;
        for (const auto& path : paths) {
            hi = std::min<int>(hi, path.size());
        }
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkCommonSubpath(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
