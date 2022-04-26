class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> cnts;
        for (const vector<int>& row : nums) {
            for (int num : row) {
                ++cnts[num];
            }
        }

        vector<int> ans;
        for (const auto& p : cnts) {
            if (p.second == nums.size()) {
                ans.push_back(p.first);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};
