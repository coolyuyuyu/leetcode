class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }

        vector<int> tmps;
        for (int num : nums) {
            if (num >= 0) {
                tmps.push_back(num);
            }
        }
        if (tmps.empty()) {
            return nums;
        }
        std::rotate(tmps.begin(), tmps.begin() + k % tmps.size(), tmps.end());

        for (int i = 0, j = 0; i < nums.size() && j < tmps.size(); ++i) {
            if (nums[i] >= 0) {
                nums[i] = tmps[j++];
            }
        }

        return nums;
    }
};
