class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int lens[n];
        for (int i = 0; i < n; ++i) {
            lens[i] = std::to_string(nums[i]).size();
        }
        int pows[7];
        pows[0] = 1;
        for (int i = 1; i < 7; ++i) {
            pows[i] = pows[i - 1] * 10 % k;
        }

        vector<int> ret;
        set<tuple<int, int, int>> cache;
        std::function<bool(int, int, int)> dfs = [&](int pos, int state, int rem) {
            if (pos >= n) {
                return (rem % k) == 0;
            }

            auto key = make_tuple(pos, state, rem);
            if (cache.find(key) != cache.end()) {
                return false;
            }

            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) { continue; }
                ret.push_back(nums[i]);
                if (dfs(pos + 1, state | (1 << i), (rem * pows[lens[i]] % k + nums[i]) % k)) {
                    return true;
                }
                ret.pop_back();
            }

            cache.insert(key);
            return false;
        };
        dfs(0, 0, 0);

        return ret;
    }
};
