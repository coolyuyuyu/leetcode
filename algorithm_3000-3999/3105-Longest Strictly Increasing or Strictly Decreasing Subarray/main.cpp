class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        auto f = [](auto bgn, auto end) {
            int ret = 0;
            int pre = INT_MIN, len = 0;
            for (auto itr = bgn; itr != end; pre = *(itr++)) {
                if (*itr > pre) {
                    len += 1;
                }
                else {
                    len = 1;
                }
                ret = std::max(ret, len);
            }

            return ret;
        };

        return std::max(f(nums.begin(), nums.end()), f(nums.rbegin(), nums.rend()));
    }
};
