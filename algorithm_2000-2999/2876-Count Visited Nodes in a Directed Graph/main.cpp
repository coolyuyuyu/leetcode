class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();

        vector<int> in(n, 0);
        for (int i = 0; i < n; ++i) {
            ++in[edges[i]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (--in[edges[v]] == 0) {
                q.push(edges[v]);
            }
        }

        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) { continue; }
            if (ret[i] != 0) { continue; }

            int len = 1;
            for (int j = edges[i]; j != i; j = edges[j]) {
                ++len;
            }
            for (int j = i; ret[j] == 0; j = edges[j]) {
                ret[j] = len;
            }
        }

        std::function<int(int)> dfs = [&](int cur) {
            int& cnt = ret[cur];
            if (0 < cnt) {
                return cnt;
            }

            cnt = 1 + dfs(edges[cur]);
            return cnt;
        };
        for (int i = 0; i < n; ++i) {
            if (ret[i] == 0) {
                dfs(i);
            }
        }

        return ret;
    }
};
