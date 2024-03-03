class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, std::greater<long long>> pq;
        for (int num : nums) {
            pq.push(num);
        }

        int ret = 0;
        for (; pq.size() >= 2 && pq.top() < k; ++ret) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            long long z = min(x, y) * 2 + max(x, y);
            pq.push(z);
        }

        return ret;
    }
};
