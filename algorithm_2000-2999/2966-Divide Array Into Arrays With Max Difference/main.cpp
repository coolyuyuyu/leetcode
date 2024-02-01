class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ret(n / 3, vector<int>(3));
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }

            vector<int>& triplet = ret[i / 3];
            std::copy(nums.begin() + i, nums.begin() + i + 3, triplet.begin());
        }

        return ret;
    }
};
