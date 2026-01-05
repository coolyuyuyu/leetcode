class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.insert(num).second == false) {
                return num;
            }
        }
        __builtin_unreachable();

        return -1;
    }
};
