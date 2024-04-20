class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> ret;
        vector<int> cnts(101, 0);
        for (const auto& array : arrays) {
            for (int num : array) {
                if (++cnts[num] == arrays.size()) {
                    ret.push_back(num);
                }
            }
        }

        return ret;
    }
};
