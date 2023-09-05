class Solution {
public:
    int M = 1e9 + 7;

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char, int> m;
        for (char c : s) {
            ++m[c];
        }
        if (m.size() < k) {
            return 0;
        }

        vector<int> freq;
        for (const auto& [_, f] : m) {
            freq.push_back(f);
        }
        std::sort(freq.rbegin(), freq.rend());

        int target = 0;
        for (int i = 0; i < k; ++i) {
            target += freq[i];
        }

        vector<int> postsum(freq.size());
        std::partial_sum(freq.rbegin(), freq.rend(), postsum.rbegin());

        long long ret = 0;
        std::function<void(int, int, int, long long)> dfs = [&](int start, int picked, int beauty, long long cnt) {
            if (picked == k) {
                if (beauty == target) {
                    ret = (ret + cnt) % M;
                }
                return;
            }
            else if (freq.size() - start < k - picked) {
                return;
            }
            else if (target < beauty) {
                return;
            }
            else if (beauty + postsum[start] < target) {
                return;
            }

            for (int i = start; i < freq.size(); ++i) {
                dfs(i + 1, picked + 1, beauty + freq[i], cnt * freq[i] % M);
            }
        };
        dfs(0, 0, 0, 1);

        return ret;
    }
};
