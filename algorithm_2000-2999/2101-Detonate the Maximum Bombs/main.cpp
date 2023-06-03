class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long a = bombs[i][0] - bombs[j][0];
                long long b = bombs[i][1] - bombs[j][1];
                long long distSquare = a * a + b * b;
                long long ri = bombs[i][2], rj = bombs[j][2];
                if (distSquare <= (ri * ri)) {
                    graph[i].push_back(j);
                }
                if (distSquare <= (rj * rj)) {
                    graph[j].push_back(i);
                }
            }
        }

        int ret = 0;
        for (int start = 0; start < n; ++start) {
            int cnt = 0;

            queue<int> q;
            vector<bool> visited(n, false);
            visited[start] = true;
            q.push(start);

            while (!q.empty()) {
                for (int i = q.size(); 0 < i--;) {
                    int node = q.front();
                    q.pop();

                    cnt += 1;

                    for (int next : graph[node]) {
                        if (visited[next]) {
                            continue;
                        }

                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            ret = std::max(ret, cnt);
        }

        return ret;
    }
};
