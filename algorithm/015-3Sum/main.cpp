class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; (i + 2) < nums.size(); ++i) {
            if (0 < i && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    result.push_back({ nums[i], nums[j], nums[k] });

                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    ++j;

                    while (j < k && nums[k] == nums[k - 1]) {
                        --k;
                    }
                     --k;
                }
                else if (0 < sum) {
                    --k;
                }
                else {
                    ++j;
                }
            }
        }

        return result;
    }
};