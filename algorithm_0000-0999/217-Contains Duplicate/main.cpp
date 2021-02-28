class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            pair<set<int>::const_iterator, bool> p = s.emplace(*iter);
            if (!p.second) {
                return true;
            }
        }

        return false;
    }
};