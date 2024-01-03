class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, pair<int, int>> num2range;
        for (int i = 0; i < n; ++i) {
            auto itr = num2range.find(nums[i]);
            if (itr == num2range.end()) {
                num2range.emplace_hint(itr, nums[i], pair<int, int>{i, i});
            }
            else {
                itr->second.second = i;
            }
        }

        int diffs[n];
        std::fill(diffs, diffs + n, 0);
        for (const auto& [_, range] : num2range) {
            diffs[range.first]++;
            diffs[range.second]--;
        }

        int sum = 0, cnt = 0;
        for (const auto& diff: diffs) {
            sum += diff;
            if (sum == 0) {
                ++cnt;
            }
        }

        std::function<int(int, int)> quickPow = [](int base, int exp) {
            int M = 1e9 + 7;

            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = (1L * ret * base) % M;
                }
                base = (1L * base * base) % M;
            }

            return ret;
        };

        return quickPow(2, cnt - 1);
    }
};
