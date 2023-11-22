class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                m[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> ret;
        for (const auto& [_, diag] : m) {
            for (int i = diag.size(); 0 < i--;) {
                ret.push_back(diag[i]);
            }
        }

        return ret;
    }
};
