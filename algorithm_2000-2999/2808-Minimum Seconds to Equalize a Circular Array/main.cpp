class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }

        int ret = INT_MAX;
        for (auto& [_, indexes] : m) {
            indexes.push_back(indexes.front() + n);

            int d = 0;
            for (int i = 1; i < indexes.size(); ++i) {
                d = std::max(d, (indexes[i] - indexes[i - 1]) / 2);
            }
            ret = std::min(ret, d);
        }

        return ret;
    }
};
