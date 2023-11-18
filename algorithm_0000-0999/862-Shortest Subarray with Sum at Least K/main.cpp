class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        long presum[n + 1];
        presum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        deque<int> dq;

        int ret = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && presum[dq.back()] >= presum[i]) {
                dq.pop_back();
            }
            while (!dq.empty() && presum[i] - presum[dq.front()] >= k) {
                ret = std::min(ret, i - dq.front());
                dq.pop_front();
            }

            dq.push_back(i);
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
