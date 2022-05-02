class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> cnts(52, 0);
        for (const auto& range : ranges) {
            cnts[range[0]] += 1;
            cnts[range[1] + 1] -= 1;
        }
        for (int i = 1; i <= right; ++i) {
            cnts[i] += cnts[i - 1];
            if (left <= i && cnts[i] <= 0) {
                return false;
            }
        }

        return true;
    }
};
