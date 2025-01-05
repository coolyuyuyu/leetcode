class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        // nums[p] * nums[r] == nums[q] * nums[s]
        // => nums[p] / nums[q] == nums[s] / nums[r]

        int n = nums.size();

        std::function<int(int, int)> createKey = [](int x, int y) {
            int g = std::gcd(x, y);
            x /= g, y /= g;

            return x * 1000 + y;
        };

        unordered_map<int, vector<int>> m;
        for (int r = 0; r < n; ++r) {
            for (int s = r + 2; s < n; ++s) {
                int key = createKey(nums[s], nums[r]);
                m[key].push_back(r);
            }
        }

        long long ret = 0;
        for (int p = 0; p < n; ++p) {
            for (int q = p + 2; q < n; ++q) {
                int key = createKey(nums[p], nums[q]);
                const vector<int>& rArr = m[key];
                ret += std::distance(std::lower_bound(rArr.begin(), rArr.end(), q + 2), rArr.end());
            }
        }

        return ret;
    }
};
