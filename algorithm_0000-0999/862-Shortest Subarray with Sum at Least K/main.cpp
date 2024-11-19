class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        long presums[n + 1];
        presums[0] = 0;
        for (int i = 0; i < n; ++i) {
            presums[i + 1] = presums[i] + nums[i];
        }

        int ret = INT_MAX;

        deque<int> dq;
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && presums[dq.back()] >= presums[i]) {
                dq.pop_back();
            }
            while (!dq.empty() && presums[i] - presums[dq.front()] >= k) {
                ret = std::min(ret, i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }

        return ret == INT_MAX ? -1: ret;
    }
};
