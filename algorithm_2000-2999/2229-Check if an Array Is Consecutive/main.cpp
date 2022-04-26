class Solution {
public:
    // Time: O(NlogN)
    bool isConsecutive_sort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] + 1 != nums[i]) {
                return false;
            }
        }
        return true;
    }

    // Time: O(N)
    bool isConsecutive_linearSwap(vector<int>& nums) {
        assert(!nums.empty());
        int n = nums.size();
        int min = *std::min_element(nums.begin(), nums.end());
        int max = min + n - 1;

        for (int i = 0; i < n;) {
            if (max < nums[i]) {
                return false;
            }

            if (nums[i] == (min + i)) {
                ++i;
                continue;
            }
            else if (nums[nums[i] - min] == nums[i]) { // repeated
                return false;
            }
            else {
                std::swap(nums[i], nums[nums[i] - min]);
            }
        }

        return true;
    }

    bool isConsecutive(vector<int>& nums) {
        //return isConsecutive_sort(nums);
        return isConsecutive_linearSwap(nums);
    }
};
