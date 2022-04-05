class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            auto p = indexes.emplace(nums[i], i);
            if (!p.second) {
                if ((i - p.first->second) <= k) {
                    return true;
                }
                p.first->second = i;
            }
        }

        return false;
    }
};
