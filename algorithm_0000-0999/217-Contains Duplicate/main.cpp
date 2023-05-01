class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.insert(num).second == false) {
                return true;
            }
        }

        return false;
    }
};
