class Solution {
public:
    int M = 1e9 + 7;
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char, int> char2cnt;
        for (char c : s) {
            ++char2cnt[c];
        }
        if (char2cnt.size() < k) {
            return 0;
        }

        vector<int> cnts;
        for (const auto& [_, cnt] : char2cnt) {
            cnts.push_back(cnt);
        };
        std::sort(cnts.rbegin(), cnts.rend());
        int n = cnts.size();
        int target = std::accumulate(cnts.begin(), cnts.begin() + k, 0);

        vector<int> postsums(n);
        std::partial_sum(cnts.rbegin(), cnts.rend(), postsums.rbegin());

        int ret = 0;
        std::function<void(int, int, int, int)> f = [&](int cur, int picked, int beauty, int prod) {
            if (picked == k) {
                if (beauty == target) {
                    ret = (ret + prod) % M;
                }
                return;
            }
            else if (n - cur < k - picked) {
                return;
            }
            else if (beauty >= target) {
                return;
            }
            else if (beauty + postsums[cur] < target) {
                return;
            }

            for (int i = cur; i < n; ++i) {
                f(i + 1, picked + 1, beauty + cnts[i], 1LL * prod * cnts[i] % M);
            }

        };
        f(0, 0, 0, 1);

        return ret;
    }
};
