class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            string s = std::to_string(nums[i]);
            pairs[i] = {s.front() - '0', s.back() - '0'};
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (std::gcd(pairs[i].first, pairs[j].second) == 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
