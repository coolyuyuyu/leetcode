class Solution {
public:
    // check a color at a time
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> graph[n];

        int inDegree[n];
        std::fill(inDegree, inDegree + n, 0);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            ++inDegree[b];
        }

        std::function<int(char)> f = [&](char color) {
            int in[n];
            std::copy(inDegree, inDegree + n, in);
            int cnt[n];
            std::fill(cnt, cnt + n, 0);
            queue<int> q;
            for (int v = 0; v < n; ++v) {
                if (in[v] == 0) {
                    cnt[v] = (colors[v] == color ? 1 : 0);
                    q.push(v);
                }
            }

            int visited = 0;
            int ret = 0;
            for (; !q.empty(); ++visited) {
                int cur = q.front();
                q.pop();

                ret = std::max(ret, cnt[cur]);

                for (int nxt : graph[cur]) {
                    cnt[nxt] = std::max(cnt[nxt], cnt[cur] + (colors[nxt] == color ? 1 : 0));
                    if (--in[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }

            return visited == n ? ret : -1;
        };
        int ret = 0;
        for (char c : unordered_set<char>(colors.begin(), colors.end())) {
            int val = f(c);
            if (val == -1) {
                return -1;
            }
            ret = std::max(ret, val);
        }

        return ret;
    }
};
