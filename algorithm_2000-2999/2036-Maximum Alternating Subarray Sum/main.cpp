class Solution {
public:
    // Time: O(N), Space: O(1)
    long long solution1(vector<int>& nums) {
        long long maxSum = INT_MIN, curSum;

        // revert nunbers at odd index, scanning from even index;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i % 2 == 1) {
                nums[i] = -nums[i];
            }
        }

        curSum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            if (maxSum < curSum) {
                maxSum = curSum;
            }

            if (curSum < 0 && i % 2 == 1) {
                curSum = 0;
            }
        }

        // revert nunbers at even index, scan from odd index;
        for (size_t i = 0; i < nums.size(); ++i) {
            nums[i] = -nums[i];
        }

        curSum = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            curSum += nums[i];
            if (maxSum < curSum) {
                maxSum = curSum;
            }

            if (curSum < 0 && i % 2 == 0) {
                curSum = 0;
            }
        }

        return maxSum;
    }

    // Time: O(N), Space: O(1)
    long long solution2(vector<int>& nums) {
        long long maxSum = INT_MIN;

        long long lastAdd = INT_MIN, lastSub = INT_MIN;
        for (int num : nums) {
            long long tmp = lastAdd;
            lastAdd = std::max(lastSub + num, (long long)(num));
            lastSub = tmp - num;
            maxSum = std::max({maxSum, lastAdd, lastSub});
        }

        return maxSum;
    }

    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        //return solution1(nums);
        return solution2(nums);
    }
};
