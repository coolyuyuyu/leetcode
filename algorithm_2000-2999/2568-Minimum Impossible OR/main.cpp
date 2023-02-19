class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int ret = 1;
        for (unordered_set<int> s(nums.begin(), nums.end()); s.find(ret) != s.end(); ret *= 2) {
            ;
        }

        return ret;
    }
};
