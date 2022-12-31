class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        auto cmp1 = [&tasks](int i, int j) {
            return tasks[i][0] > tasks[j][0];
        };
        priority_queue<int, vector<int>, decltype(cmp1)> pq1(cmp1);
        for (int i = 0; i < n; ++i) {
            pq1.push(i);
        }

        auto cmp2 = [&tasks](int i, int j) {
            return tasks[i][1] > tasks[j][1] || (tasks[i][1] == tasks[j][1] && i > j);
        };
        priority_queue<int, vector<int>, decltype(cmp2)> pq2(cmp2);


        vector<int> ret;
        for (long long curTime = 0; !pq1.empty() || !pq2.empty();) {
            for (; !pq1.empty() && tasks[pq1.top()][0] <= curTime; pq1.pop()) {
                pq2.push(pq1.top());
            }

            if (!pq2.empty()) {
                int i = pq2.top();
                pq2.pop();
                curTime += tasks[i][1];

                ret.push_back(i);
            }
            else { // idle
                curTime = tasks[pq1.top()][0];
            }
        }

        return ret;
    }
};
