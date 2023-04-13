class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<set<int>> nexts(n);
        vector<int> degrees(n, 0);
        for (const auto& edge : edges) {
            nexts[edge[0]].insert(edge[1]);
            nexts[edge[1]].insert(edge[0]);
            ++degrees[edge[0]];
            ++degrees[edge[1]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1 && coins[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int i = q.front();
            q.pop();

            degrees[i] = 0;
            for (int j : nexts[i]) {
                if (--degrees[j] == 1 && coins[j] == 0) {
                    q.push(j);
                    nexts[j].erase(i);
                }
            }
        }

        auto strip = [&]() {
            for (int i = 0; i < n; ++i) {
                if (degrees[i] == 1) {
                    q.push(i);
                }
            }
            while(!q.empty()) {
                int i = q.front();
                q.pop();

                degrees[i] = 0;
                for (int j : nexts[i]) {
                    if (--degrees[j] == 1) {
                        nexts[j].erase(i);
                    }
                }
            }
        };
        strip();
        strip();

        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (0 < degrees[i]) {
                ++m;
            }
        }

        return m == 0 ? 0 : (m - 1) * 2;
    }
};

// 1. trim branch where the end does not contain coin.
// 2. we can collect the coins that are at a distance of at most 2
//     => strip the outmost ends 2 times
// 3. the minimum number of edges that we need to go through
//     => (m - 1) * 2, where m = the number of remaining nodes.
