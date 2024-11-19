class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        std::function<int(int)> findPower = [&](int i) {
            for (int j = 1; j < k; ++j) {
                if (nums[i] + j != nums[i + j]) {
                    return -1;
                }
            }

            return nums[i + k - 1];
        };

        int n = nums.size();
        vector<int> ret(n + 1 - k);
        for (int i = 0; i < ret.size(); ++i) {
            ret[i] = findPower(i);
        }

        return ret;
    }
};
