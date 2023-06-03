class Solution {
public:
    int bsearch(const vector<int>& nums, int x, int y) {
        std::function<bool(int)> makeNonPositive = [&](long numOp) {
            long diff = numOp * y;
            for (long num : nums) {
                num -= diff;
                if (0 < num) {
                    numOp -= ceil(num * 1.0 / (x - y));
                    if (numOp < 0) {
                        return false;
                    }
                }
            }

            return true;
        };

        int lo = 0, hi = INT_MAX / 2;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (makeNonPositive(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int minOperations(vector<int>& nums, int x, int y) {
        return bsearch(nums, x, y);
    }
};
