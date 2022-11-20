class Solution {
public:
    bool computeArriveTimes(const vector<vector<int>>& graph, int cur, int pre, int dst, int depth, vector<int>& times) {
        bool found = false;
        if (cur == dst) {
            times[cur] = depth;
            found = true;
        }
        else {
            for (int neighbor : graph[cur]) {
                if (neighbor == pre) {
                    continue;
                }

                found = computeArriveTimes(graph, neighbor, cur, dst, depth + 1, times);
                if (found) {
                    times[cur] = depth;
                    break;
                }
            }
        }

        return found;
    }

    void computePathIncome(const vector<vector<int>>& graph, int cur, int pre, int depth, vector<int>& times, vector<int>& amount, int income, int& ans) {
        if (depth < times[cur]) {
            income += amount[cur];
        }
        else if (depth == times[cur]) {
            income += (amount[cur] / 2);
        }

        bool isLeaf = true;
        for (int neighbor : graph[cur]) {
            if (neighbor == pre) {
                continue;
            }

            isLeaf = false;
            computePathIncome(graph, neighbor, cur, depth + 1, times, amount, income, ans);
        }

        if (isLeaf && ans < income) {
            ans = income;
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> neighbors(amount.size());
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        vector<int> times(amount.size(), INT_MAX);
        computeArriveTimes(neighbors, bob, -1, 0, 0, times);

        int ans = INT_MIN;
        computePathIncome(neighbors, 0, -1, 0, times, amount, 0, ans);

        return ans;
    }
};
