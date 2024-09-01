class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ret = 0;
        std::function<int(int, int)> f = [&](int cur, int pre) {
            int cnt = 0;

            int childCnt = -1;
            bool sameCnt = true;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                int c = f(nxt, cur);
                cnt += c;
                if (childCnt == -1) {
                    childCnt = c;
                }
                else if (c != childCnt) {
                    sameCnt = false;
                }
            }
            if (sameCnt) {
                ++ret;
            }

            return cnt + 1;
        };
        f(0, -1);

        return ret;
    }
};
