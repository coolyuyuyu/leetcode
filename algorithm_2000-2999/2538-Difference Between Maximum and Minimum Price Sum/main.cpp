class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<int> next[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        // Fix a node as the root. For each node, find the maximal path where one downard end is leaf and the other downard end is a non-leaf.

        int sum1[n]; // sum1[node]: the maximal path from node to its non-leaf
        int sum2[n]; // sum2[node]: the maximal path from node to its leaf
        std::fill(sum1, sum1 + n, 0);
        std::fill(sum2, sum2 + n, 0);
        int root = 0;

        std::function<void(int, int)> dfs1 = [&](int cur, int pre) {
            if (next[cur].size() == 1 && next[cur][0] == pre) { // leaf
                sum1[cur] = 0;
                sum2[cur] = price[cur];
                return;
            }

            for (int nxt : next[cur]) {
                if (nxt == pre) { continue; }
                dfs1(nxt, cur);
                sum1[cur] = std::max(sum1[cur], sum1[nxt] + price[cur]);
                sum2[cur] = std::max(sum2[cur], sum2[nxt] + price[cur]);
            }
        };
        dfs1(root, -1);

        int ret = 0;
        std::function<void(int, int)> dfs2 = [&](int cur, int pre) {
            if (cur == root) {
                ret = std::max(ret, sum2[cur] - price[cur]);
            }

            vector<pair<int, int>> arr1; // <sum1[node], node>
            vector<pair<int, int>> arr2; // <sum2[node], node>
            for (int nxt : next[cur]) {
                if (nxt == pre) { continue; }
                dfs2(nxt, cur);
                arr1.emplace_back(sum1[nxt], nxt);
                arr2.emplace_back(sum2[nxt], nxt);
            }
            std::sort(arr1.rbegin(), arr1.rend());
            std::sort(arr2.rbegin(), arr2.rend());

            if (arr1.size() >= 2) {
                if (arr1[0].second == arr2[0].second) {
                    ret = std::max({ret, arr1[0].first + price[cur] + arr2[1].first, arr1[1].first + price[cur] + arr2[0].first});
                }
                else {
                    ret = std::max({ret, arr1[0].first + price[cur] + arr2[0].first});
                }
            }
            else if (arr1.size() == 1) {
                ret = std::max(ret, sum1[cur]);
            }

        };
        dfs2(root, -1);

        return ret;
    }
};
