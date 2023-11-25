class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *std::max_element(nums.begin(), nums.end());

        std::function<bool(int)> checkLE = [&](int div) {
            int sum = 0;
            for (int num : nums) {
                sum += std::ceil(num * 1.0 / div);
                if (sum > threshold) {
                    return false;
                }
            }

            return true;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkLE(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
