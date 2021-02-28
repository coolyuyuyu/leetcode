class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = M.size();
        vector<bool> visited(count, false);

        int groupCount = 0;
        for (int i = 0; i < count; ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            ++groupCount;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (int b = 0; b < count; ++b) {
                    if (visited[b] == false && M[a][b]) {
                        visited[b] = true;
                        q.push(b);
                    }
                }
            }
        }

        return groupCount;
    }
};