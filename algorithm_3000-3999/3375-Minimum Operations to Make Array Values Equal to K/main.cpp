class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        if (*s.begin() < k) {
            return -1;
        }

        return s.size() - (s.find(k) == s.end() ? 0 : 1);
    }
};
