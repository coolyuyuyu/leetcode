class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        std::function<void(int)> f = [&](int begin) {
            if (nums.size() <= begin) {
                ret.push_back(nums);
            }

            unordered_set<int> visited;
            for (int i = begin; i < nums.size(); ++i) {
                if (visited.insert(nums[i]).second) {
                    std::swap(nums[begin], nums[i]);
                    f(begin + 1);
                    std::swap(nums[begin], nums[i]);
                }
            }
        };
        f(0);

        return ret;
    }
};
