class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != (m * n)) {
            return {};
        }

        vector<vector<int>> converted;
        for (auto itr = original.begin(); itr != original.end(); itr += n) {
            converted.emplace_back(itr, itr + n);

        }
        return converted;
    }
};
