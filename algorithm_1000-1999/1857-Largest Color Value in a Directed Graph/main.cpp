class Solution {
public:
    // check a color at a time
    int f1(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> graph[n];
        vector<int> in(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            ++in[v];
        }

        std::function<int(char color, vector<int>)> f = [&](char color, vector<int> in) {
            int cnts[n]; std::fill(cnts, cnts + n, 0);
            queue<int> q;
            for (int v = 0; v < n; ++v) {
                if (in[v] == 0) {
                    cnts[v] = (colors[v] == color ? 1 : 0);
                    q.push(v);
                }
            }

            int visited = 0;
            for (; !q.empty(); ++visited) {
                auto cur = q.front();
                q.pop();

                for (int nxt : graph[cur]) {
                    cnts[nxt] = std::max(cnts[nxt], cnts[cur] + (colors[nxt] == color ? 1 : 0));
                    if (--in[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }

            return visited == n ? *std::max_element(cnts, cnts + n) : -1;
        };

        int ret = 0;
        for (char color : unordered_set<char>(colors.begin(), colors.end())) {
            int val = f(color, in);
            if (val == -1) {
               return -1;
            }
            ret = std::max(ret, val);
        }

        return ret;
    }

    // check all colors altogether
    int f2(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> colorIndexes;
        for (char color : unordered_set<char>(colors.begin(), colors.end())) {
            colorIndexes.push_back(color - 'a');
        }

        vector<int> graph[n];
        vector<int> in(n, 0);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            ++in[b];
        }

        int cnts[n][26];
        for (int i = 0; i < n; ++i) {
            for (int j : colorIndexes) {
                cnts[i][j] = 0;
            }
        }

        int ret = 0;

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                ++cnts[i][colors[i] - 'a'];
                ret = 1;
                q.push(i);
            }
        }

        int visited = 0;
        for (; !q.empty(); ++visited) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                for (int j : colorIndexes) {
                    cnts[nxt][j] = std::max(cnts[nxt][j], cnts[cur][j] + ('a' + j == colors[nxt] ? 1 : 0));
                    ret = std::max(ret, cnts[nxt][j]);
                }

                if (--in[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        return visited == n ? ret : -1;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        return f1(colors, edges);
        //return f2(colors, edges);
    }
};
