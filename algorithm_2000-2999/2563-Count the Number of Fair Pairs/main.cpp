class Solution {
public:
    long long f1(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        std::function<long long(int)> countLE = [&](int target) {
            long long ret = 0;
            for (int lft = 0, rht = n - 1; lft < rht; ++lft) {
                while (lft < rht && nums[lft] + nums[rht] > target) {
                    --rht;
                }

                ret += (rht - lft);
            }
            return ret;
        };

        return countLE(upper) - countLE(lower - 1);
    }

    long long f2(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());

        long long ret = 0;
        for (int num : nums) {
            auto bgn = std::lower_bound(nums.begin(), nums.end(), lower - num);
            auto end = std::upper_bound(nums.begin(), nums.end(), upper - num);
            ret += std::distance(bgn, end);
            if (lower - num <= num && num <= upper - num) {
                ret -= 1;
            }
        }

        return ret / 2;
    }

    long long f3(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());

        long long ret = 0;
        for (int i = 0, n = nums.size(), lft = n - 1, rht = n - 1; i < n; ++i) {
            while (lft >= 0 && lower <= nums[lft] + nums[i]) {
                --lft;
            }
            while (rht >= 0 && nums[i] + nums[rht] > upper) {
                --rht;
            }
            ret += (rht - lft);
            if (lft < i && i <= rht) {
                ret -= 1;
            }
        }
        return ret / 2;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        //return f1(nums, lower, upper);
        //return f2(nums, lower, upper);
        return f3(nums, lower, upper);
    }
};
