class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        std::function<int(vector<int>, int, int)> canMakeEqualT = [](vector<int> nums, int k, int target) {
            for (int i = 0; i + 1 < nums.size(); ++i) {
                if (nums[i] != target) {
                    if (--k < 0) {
                        return false;
                    }
                    nums[i + 1] *= -1;
                }
            }
            return nums.back() == target;
        };

        return canMakeEqualT(nums, k, 1) || canMakeEqualT(nums, k, -1);
    }
};
