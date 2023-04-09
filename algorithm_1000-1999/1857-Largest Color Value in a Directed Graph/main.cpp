class Solution {
public:
    int helper(const string& colors, const vector<vector<int>>& nexts, vector<int> inDegrees, char c) {
        int n = nexts.size();

        int ret = 0;

        queue<int> q;
        vector<int> counts(nexts.size(), 0);
        for (int v = 0; v < nexts.size(); ++v) {
            if (inDegrees[v] == 0) {
                counts[v] = (colors[v] == c ? 1 : 0);
                ret = std::max(ret, counts[v]);
                --n;
                q.push(v);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int next : nexts[v]) {
                counts[next] = std::max(counts[next], counts[v] + (colors[next] == c ? 1 : 0));
                ret = std::max(ret, counts[next]);
                if (--inDegrees[next] == 0) {
                    --n;
                    q.push(next);
                }
            }
        }

        return n == 0 ? ret : -1;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>> nexts(n);
        vector<int> inDegrees(n, 0);
        for (const auto& edge : edges) {
            nexts[edge[0]].push_back(edge[1]);
            ++inDegrees[edge[1]];
        }

        int ret = 0;
        for (char c : unordered_set<char>(colors.begin(), colors.end())) {
            int val = helper(colors, nexts, inDegrees, c);
            if (val == -1) {
                return -1;
            }
            ret = std::max(ret, val);
        }

        return ret;
    }
};
