class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (const auto& op : ops) {
            m = std::min(m, op[0]);
            n = std::min(n, op[1]);
        }

        return m * n;
    }
};
