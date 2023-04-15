class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        int len = targetPath.size();

        vector<vector<int>> graph(n);
        for (const auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        // dp[i][j]: the minimum edit distance of a path such that the ith stop is city j
        vector<vector<int>> dp(len, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> prev(len, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = (names[j] == targetPath[0] ? 0 : 1);
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int next : graph[j]) {
                    int dist = dp[i - 1][next] + (names[j] == targetPath[i] ? 0 : 1);
                    if (dist < dp[i][j]) {
                        dp[i][j] = dist;
                        prev[i][j] = next;
                    }
                }   
            }
        }

        int end = 0; {
            int minDist = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (dp[len - 1][j] < minDist) {
                    minDist = dp[len - 1][j];
                    end = j;
                }
            }
        }

        vector<int> ret(len);
        for (int i = len, v = end; 0 < i--;) {
            ret[i] = v;
            v = prev[i][v];
        }
        
        return ret;
    }
};