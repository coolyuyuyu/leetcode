class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> sums(nums.size(), 0); {
            int sum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                sums[i] = sum;
                if (sum == k) {
                    ++count;
                }
            }
        }

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                sums[j] -= nums[i - 1];
                if (sums[j] == k) {
                    ++count;
                }
            }
        }

        return count;
    }
};