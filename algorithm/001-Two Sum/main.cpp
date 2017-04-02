class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            int y = target - x;

            unordered_map<int, int>::const_iterator it = indexes.find(y);
            if (it != indexes.end()) {
                return {it->second, i};
            } 
            indexes.emplace(x, i);
        }
        return {0, 0};
    }
};