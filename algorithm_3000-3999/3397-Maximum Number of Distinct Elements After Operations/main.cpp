class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ret = 1;
        nums[0] -= k;
        for (int i = 1; i < nums.size(); ++i) {\
            if (nums[i - 1] + 1 < nums[i] - k) {
                nums[i] = nums[i] - k;
            }
            else if (nums[i - 1] + 1 <= nums[i] + k) {
                nums[i] = nums[i - 1] + 1;
            }
            else {
                nums[i] = nums[i] + k;
            }

            if (nums[i - 1] != nums[i]) {
                ++ret;
            }
        }

        return ret;
    }
};
