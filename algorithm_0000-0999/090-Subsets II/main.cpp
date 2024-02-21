class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        std::function<void(vector<int>& , int i)> dfs = [&](vector<int>& comb, int i) {
            if (i >= n) {
                ret.push_back(comb);
                return;
            }

            comb.push_back(nums[i]);
            dfs(comb, i + 1);
            comb.pop_back();

            if (comb.empty() || comb.back() != nums[i]) {
                dfs(comb, i + 1);
            }
        };
        vector<int> comb;
        dfs(comb, 0);

        return ret;
    }
};
