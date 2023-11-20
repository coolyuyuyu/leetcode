class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == m) { return n; }

        arr.insert(arr.begin(), 0);

        int step[n + 1];
        for (int i = 0; i <= n; ++i) {
            step[arr[i]] = i;
        }

        deque<int> dq;

        int ret = -1;
        for (int i = 1; i <= n; ++i) {
            if (!dq.empty() && dq.front() == i - m) {
                dq.pop_front();
            }
            while (!dq.empty() && step[dq.back()] <= step[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (m <= i) {
                int last = step[dq.front()];
                int lftBound = (i == m ? INT_MAX : step[i - m]);
                int rhtBound = (i == n ? INT_MAX : step[i + 1]);
                if (last < lftBound && last < rhtBound) {
                    ret = std::max(ret, std::min(lftBound, rhtBound) - 1);
                }
            }
        }

        return ret;
    }
};
