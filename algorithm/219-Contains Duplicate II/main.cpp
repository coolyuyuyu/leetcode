class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            pair<unordered_map<int, int>::iterator, bool> p = indexes.emplace(nums[i], i);
            if (p.second == false) {
                if ((i - p.first->second) <= k) {
                    return true;
                }
                p.first->second = i;
            }
        }

        return false;
    }
};