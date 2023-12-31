class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ret(n / 3, vector<int>(3));
        for (int i = 0; i < n; i += 3) {
            auto& triplet = ret[i / 3];
            triplet[0] = nums[i];
            triplet[1] = nums[i + 1];
            triplet[2] = nums[i + 2];
            if (triplet[2] - triplet[0] > k) {
                return {};
            }
        }

        return ret;
    }
};
