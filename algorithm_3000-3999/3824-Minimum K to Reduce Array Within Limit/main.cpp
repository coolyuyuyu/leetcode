class Solution {
public:
    int minimumK(vector<int>& nums) {
        std::function<bool(int)> checkOk = [&](int k) {
            int ret = 0;
            for (int num : nums) {
                ret += (num + k - 1) / k;
            }
            return ret <= 1LL * k * k;
        };

        int lo = 1, hi = 1e5;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
