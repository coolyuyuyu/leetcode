class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> nexts(n);
        for (const auto& edge : edges) {
            nexts[edge[0]].push_back(edge[1]);
            nexts[edge[1]].push_back(edge[0]);
        }

        vector<int> sum1(n, 0); // sum1[i]: the sum of prices from i to its non-leaf
        vector<int> sum2(n, 0); // sum2[i]: the sum of prices from i to its leaf

        int ans = 0;
        dfs1(nexts, 0, -1, price, sum1, sum2);
        dfs2(nexts, 0, -1, price, sum1, sum2, ans);
        return ans;
    }

    void dfs1(const vector<vector<int>>& nexts, int cur, int pre, const vector<int>& price, vector<int>& sum1, vector<int>& sum2) {
        if (nexts[cur].size() == 1 && nexts[cur][0] == pre) { // leaf
            sum1[cur] = 0;
            sum2[cur] = price[cur];
            return;
        }

        for (int next : nexts[cur]) {
            if (next == pre) {
                continue;
            }

            dfs1(nexts, next, cur, price, sum1, sum2);
            sum1[cur] = std::max(sum1[cur], sum1[next] + price[cur]);
            sum2[cur] = std::max(sum2[cur], sum2[next] + price[cur]);
        }
    }

    void dfs2(const vector<vector<int>>& nexts, int cur, int pre, const vector<int>& price, const vector<int>& sum1, const vector<int>& sum2, int& ans) {
        if (cur != 0) {
            ans = std::max(ans, sum2[cur]);
        }

        vector<pair<int, int>> arr1; // arr1[i]: <sum1[node], node>
        vector<pair<int, int>> arr2; // arr2[i]: <sum2[node], node>
        for (int next : nexts[cur]) {
            if (next == pre) {
                continue;
            }

            dfs2(nexts, next, cur, price, sum1, sum2, ans);
            arr1.emplace_back(sum1[next], next);
            arr2.emplace_back(sum2[next], next);
        }
        sort(arr1.rbegin(), arr1.rend());
        sort(arr2.rbegin(), arr2.rend());

        if (2 <= arr1.size()) {
            if (arr1[0].second != arr2[0].second) {
                ans = std::max(ans, arr1[0].first + arr2[0].first + price[cur]);
            }
            else {
                ans = std::max({ans, arr1[0].first + arr2[1].first + price[cur], arr1[1].first + arr2[0].first + price[cur]});
            }
        }
        else if (1 == arr1.size()) {
            ans = std::max(ans, sum1[cur]);
        }
    }
};
