class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        vector<vector<int>> rows;
        for (auto [num, cnt] : cnts) {
            if (rows.size() < cnt) {
                rows.resize(cnt);
            }
            for (int i = 0; i < cnt; ++i) {
                rows[i].push_back(num);
            }
        }

        return rows;
    }
};
