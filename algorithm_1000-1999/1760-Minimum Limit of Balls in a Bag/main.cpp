class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        std::function<bool(int)> f = [&](int target) {
            int cntOperations = 0;
            for (int num : nums) {
                cntOperations += (num + target - 1) / target - 1;
                if (cntOperations > maxOperations) {
                    return false;
                }
            }
            return true;
        };

        int lo = 1, hi = *std::max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
