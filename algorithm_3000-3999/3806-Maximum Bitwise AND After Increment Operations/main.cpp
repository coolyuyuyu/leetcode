class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();

        std::function<int(int, int)> minReach = [](int num, int mask) {
            int ret = 0;
            bool gt = false;
            for (int b = 30; b >= 0; --b) {
                int cur = (num >> b) & 1;
                int req = (mask >> b) & 1;
                if (gt) {
                    ret |= (req << b);
                }
                else {
                    if (req) {
                        ret |= (1 << b);
                        if (!cur) {
                            gt = true;
                        }
                    }
                    else {
                        ret |= (cur << b);
                    }
                }
            }

            return ret;
        };

        std::function<bool(int)> checkOk = [&](int mask) {
            int costs[n];
            for (int i = 0; i < n; ++i) {
                costs[i] = minReach(nums[i], mask) - nums[i];
            }
            std::nth_element(costs, costs + m - 1, costs + n);

            int remaining = k;
            for (int i = 0; i < m; ++i) {
                remaining -= costs[i];
                if (remaining < 0) {
                    return false;
                }
            }

            return true;
        };

        int ret = 0;
        for (int b = 30; b >= 0; --b) {
            int tmp = ret | (1 << b);
            if (checkOk(tmp)) {
                ret = tmp;
            }
        }

        return ret;
    }
};
