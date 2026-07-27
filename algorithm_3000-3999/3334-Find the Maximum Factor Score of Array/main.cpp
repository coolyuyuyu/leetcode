class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();

        long long g = 0, l = 1;
        for (int i = 0; i < n; ++i) {
            g = std::gcd(g, nums[i]);
            l = std::lcm(l, nums[i]);
        }
        long long ret = 1LL * g * l;

        for (int skip = 0; skip < n; ++skip) {
            long long g = 0, l = 1;
            for (int i = 0; i < n; ++i) {
                if (i == skip) { continue; }
                g = std::gcd(g, nums[i]);
                l = std::lcm(l, nums[i]);
            }
            ret = std::max(ret, 1LL * g * l);
        }

        return ret;
    }
};
