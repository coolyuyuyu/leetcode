class Solution {
public:
    void subsetsWithDup(const vector<pair<int, size_t>>& elems, size_t level, vector<int>& result, vector<vector<int>>& results) {
        if (elems.size() <= level) {
            results.push_back(result);
            return;
        }

        subsetsWithDup(elems, level + 1, result, results);

        int num = elems[level].first;
        size_t count = elems[level].second;
        for (size_t i = 0; i < count; ++i) {
            result.push_back(num);
            subsetsWithDup(elems, level + 1, result, results);
        }
        for (size_t i = 0; i < count; ++i) {
            result.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, size_t> counts; {
            for (int num : nums) {
                ++counts[num];
            }
        }
        vector<pair<int, size_t>> elems(counts.begin(), counts.end());

        vector<int> result;
        vector<vector<int>> results;
        subsetsWithDup(elems, 0, result, results);
        return results;
    }
};