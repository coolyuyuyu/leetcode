class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> next(n);
        for (int i = 1; i < n; ++i) {
            next[parent[i]].push_back(i);
        }

        long long ret = 0;
        unordered_map<int, int> cnts; // state -> cnt
        std::function<void(int, int)> dfs = [&](int node, int state) {
            if (cnts.find(state) != cnts.end()) {
                ret += cnts[state];
            }
            for (char c = 'a'; c <= 'z'; ++c) {
                int s = state ^ (1 << (c - 'a'));
                if (cnts.find(s) != cnts.end()) {
                    ret += cnts[s];
                }
            }

            ++cnts[state];

            for (int child : next[node]) {
                dfs(child, state ^ (1 << (s[child] - 'a')));
            }
        };
        dfs(0, 0);

        return ret;
    }
};
