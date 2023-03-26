class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> in(n, 0);
        for (int i = 0; i < n; ++i) {
            int j = edges[i];
            if (j != -1) {
                ++in[j];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (edges[i] != -1 && --in[edges[i]] == 0) {
                q.push(edges[i]);
            }
        }

        int ret = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                continue;
            }

            for (int j = i, len = 0; edges[j] != -1; j = edges[j], ++len) {
                if (visited[j]) {
                    ret = std::max(ret, len);
                    break;
                }
                visited[j] = true;
            }
        }

        return ret == 0 ? -1: ret;
    }
};
