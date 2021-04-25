class Solution {
public:
    bool check(vector<int>& nums) {
        size_t index = 1;
        while (index < nums.size() && nums[index - 1] <= nums[index]) {
            ++index;
        }
        if (nums.size() <= index) {
            return true;
        }

        ++index;
        while (index < nums.size() && nums[index - 1] <= nums[index]) {
            ++index;
        }
        if (index < nums.size()) {
            return false;
        }

        return (nums.back() <= nums.front());
    }
};
