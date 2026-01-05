class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (k == 0) { return nums.size(); }

        std::sort(nums.begin(), nums.end());
        int i = nums.size() - k;
        while (i - 1 >= 0 && nums[i - 1] == nums[i]) {
            --i;
        }

        return i;
    }
};
