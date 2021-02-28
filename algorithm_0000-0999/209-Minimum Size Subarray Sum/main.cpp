class Solution {
public:
    size_t minSubArrayLenByPartialSum(int s, vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());

        auto itr = lower_bound(nums.begin(), nums.end(), s);
        if (itr == nums.end()) {
            return 0;
        }

        size_t len = itr - nums.begin() + 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            size_t end = min(len + i - 1, nums.size());
            for (size_t j = i; j < end; ++j) {
                if (nums[j] - nums[i - 1] >= s) {
                    len = min(len, j - i + 1);
                    break;
                }
            }
        }

        return len;
    }

    size_t minSubArrayLenByLinearScan(int s, vector<int>& nums) {
        size_t len = 0;
        int sum = 0;
        while (len < nums.size() && sum < s) {
            sum += nums[len];
            ++len;
        }
        if (sum < s) {
            return 0;
        }

        size_t lft = 0, rht = len;
        while (rht < nums.size()) {
            if (sum < s) {
                sum += nums[rht++];
            }
            else {
                len = min(len, rht - lft);
                sum -= nums[lft++];
            }
        }

        while (lft < nums.size() && sum >= s) {
            len = min(len, rht - lft);
            sum -= nums[lft++];
        }

        return len;
    }

    size_t minSubArrayLen(int s, vector<int>& nums) {
        assert(0 < s);

        //return minSubArrayLenByPartialSum(s, nums);

        return minSubArrayLenByLinearScan(s, nums);
    }
};