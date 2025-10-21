class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ret = k;
        while (s.find(ret) != s.end()) {
            ret += k;
        }

        return ret;
    }
};
