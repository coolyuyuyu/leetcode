class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        vector<int> childs[n];
        int out[n]; // out degree
        std::fill(out, out + n, 0);
        for (int node = 0; node < n; ++node) {
            if (parent[node] >= 0) {
                childs[parent[node]].push_back(node);
                ++out[parent[node]];
            }
        }

        queue<int> q;
        for (int node = 0; node < n; ++node) {
            if (out[node] == 0) {
                q.push(node);
            }
        }

        int ret = 0;
        int len[n]; // the length of longest valid down path
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int len1 = 0, len2 = 0;
            for (int child : childs[node]) {
                if (s[node] == s[child]) { continue; }
                if (len[child] >= len1) {
                    len2 = len1, len1 = len[child];
                }
                else if (len[child] > len2) {
                    len2 = len[child];
                }
            }
            len[node] = 1 + len1;

            ret = std::max(ret, len1 + 1 + len2);

            if (parent[node] >= 0 && --out[parent[node]] == 0) {
                q.push(parent[node]);
            }
        }

        return ret;
    }
};
