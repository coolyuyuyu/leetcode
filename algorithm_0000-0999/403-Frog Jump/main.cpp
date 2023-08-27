class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int> s;
        for (int stone : stones) {
            s.insert(stone);
        }

        set<pair<int, int>> failed;
        std::function<int(int, int)> dfs = [&](int pos , int jump) {
            if (pos == stones.back()) {
                return true;
            }
            if (s.find(pos) == s.end()) {
                return false;
            }
            if (failed.find({pos, jump}) != failed.end()) {
                return false;
            }

            if (1 < jump && dfs(pos + jump - 1, jump - 1)) {
                return true;
            }
            if (0 < jump && dfs(pos + jump, jump)) {
                return true;
            }
            if (dfs(pos + jump + 1, jump + 1)) {
                return true;
            }

            failed.insert({pos, jump});
            return false;
        };

        return dfs(0, 0);

    }
};
