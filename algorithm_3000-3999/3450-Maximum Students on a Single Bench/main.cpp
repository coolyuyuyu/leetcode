class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        unordered_map<int, unordered_set<int>> m;
        for (const auto& d : students) {
            int sid = d[0], bid = d[1];
            m[bid].insert(sid);
        }

        int ret = 0;
        for (const auto& [_, sids] : m) {
            ret = std::max<int>(ret, sids.size());
        }

        return ret;
    }
};
