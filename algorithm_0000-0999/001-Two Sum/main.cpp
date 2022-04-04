class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            auto itr = indexes.find(target - nums[i]);
            if (itr != indexes.end()) {
                return {itr->second, i};
            }
            else {
                indexes.emplace(nums[i], i);
            }
        }

        return {-1, -1};
    }
};
