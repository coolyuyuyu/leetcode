class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<set<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        auto f = [&graph](int i, int j) {
            return graph[i].find(j) == graph[i].end();

        };

        vector<int> odds;
        for (int i = 1; i <= n; ++i) {
            if (graph[i].size() % 2 == 1) {
                odds.push_back(i);
            }
        }
        if (odds.size() == 0) {
            return true;
        }
        else if (odds.size() == 1 || odds.size() == 3) {
            return false;
        }
        else if (odds.size() == 2) {
            int a = odds[0], b = odds[1];
            if (f(a, b)) {
                return true;
            }
            else {
                for (int i = 1; i <= n; ++i) {
                    if (f(i, a) && f(i, b)) {
                        return true;
                    }
                }

                return false;
            }
        }
        else if (odds.size() == 4) {
            int a = odds[0], b = odds[1], c = odds[2], d = odds[3];
            if ((f(a, b) && f(c, d)) ||
                (f(a, c) && f(b, d)) ||
                (f(a, d) && f(b, c))) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};
