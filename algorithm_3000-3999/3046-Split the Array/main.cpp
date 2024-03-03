class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            if (++cnts[num] >= 3) {
                return false;
            }
        }

        return true;
    }
};
