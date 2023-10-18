class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int in[n];
        for (int i = 0; i < n; ++i) {
            in[i] = 0;
        }

        vector<int> graph[n];
        for (const auto& relation: relations) {
            graph[relation[0] - 1].push_back(relation[1] - 1);
            ++in[relation[1] - 1];
        }

        int completedTime[n];
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                completedTime[i] = time[i];
                q.emplace(i);
            }
            else {
                completedTime[i] = 0;
            }
        }

        int ret = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            ret = std::max(ret, completedTime[cur]);

            for (int nxt : graph[cur]) {
                completedTime[nxt] = std::max(completedTime[nxt], completedTime[cur] + time[nxt]);
                if (--in[nxt] == 0) {
                    q.emplace(nxt);
                }
            }
        }

        return ret;
    }
};
