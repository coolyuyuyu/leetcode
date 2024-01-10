class Solution {
public:
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        int n = colors.size();

        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ret = 0;
        std::function<int(int, int)> dfs = [&](int cur, int pre) {
            int cnt = 1;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }


                auto childCnt = dfs(nxt, cur);
                if (colors[nxt] == colors[cur] && cnt > 0 && childCnt > 0) {
                    cnt += childCnt;
                }
                else {
                    cnt = 0;
                }
            }

            ret = std::max(ret, cnt);

            return cnt;
        };
        dfs(0, -1);

        return ret;
    }
};
