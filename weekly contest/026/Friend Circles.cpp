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
            stack<int> stk;
            stk.push(i);
            while (!stk.empty()) {
                int a = stk.top();
                stk.pop();
                for (int b = 0; b < count; ++b) {
                    if (visited[b] == false && M[a][b]) {
                        visited[b] = true;
                        stk.push(b);
                    }
                }
            }
        }

        return groupCount;
    }
};