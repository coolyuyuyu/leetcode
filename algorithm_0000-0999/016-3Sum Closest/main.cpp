class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; (i + 2) < nums.size(); ++i) {
            if (0 < i && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                else {
                    if (abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }

                    if (target < sum) {
                        while (j < k && nums[k] == nums[k - 1]) {
                            --k;
                        }
                        --k;
                    }
                    else {
                        while (j < k && nums[j] == nums[j + 1]) {
                            ++j;
                        }
                        ++j;
                    }
                }
            }
        }

        return closest;
    }
};