class Solution {
public:
    vector<vector<int>> permute(int n) {
        vector<vector<int>> ret;

        vector<int> perm;
        std::function<void(int)> dfs = [&](int state) {
            if (perm.size() == n) {
                ret.push_back(perm);
                return;
            }

            for (int i = (perm.back() & 1) + 1; i <= n; i += 2) {
                if (state >> (i - 1) & 1) { continue; }
                perm.push_back(i);
                dfs(state | (1 << (i - 1)));
                perm.pop_back();
            }
        };
        for (int i = 1; i <= n; ++i) {
            perm.push_back(i);
            dfs(1 << (i - 1));
            perm.pop_back();
        }

        return ret;
    }
};
