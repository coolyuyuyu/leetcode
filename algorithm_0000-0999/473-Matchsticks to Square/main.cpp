class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int perimeter = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int side = perimeter / 4;
        if (side * 4 != perimeter) {
            return false;
        }

        std::sort(matchsticks.begin(), matchsticks.end()); // optimization 1: to avoid duplicate branch
        std::reverse(matchsticks.begin(), matchsticks.end()); // optimization 2: sum is getting over side earlier

        bool visited[n];
        std::fill(visited, visited + n, false);
        std::function<bool(int, int, int)> dfs = [&](int cur, int group, int sum) {
            if (group >= 4) { return true; }
            else if (sum > side) { return false; }
            else if (sum == side) { return dfs(0, group + 1, 0); }

            for (int i = cur, last = -1; i < n; ++i) {
                if (visited[i]) { continue; }
                if (matchsticks[i] == last) { continue; }

                visited[i] = true;
                last = matchsticks[i];
                if (dfs(i + 1, group, sum + matchsticks[i])) {
                    return true;
                }
                visited[i] = false;
            }

            return false;
        };

        return dfs(0, 0, 0);
    }
};
