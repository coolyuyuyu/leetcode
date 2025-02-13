class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, std::greater<long long>> pq(nums.begin(), nums.end());

        int ret = 0;
        for (; pq.size() >= 2 && pq.top() < k; ++ret) {
            long long mn = pq.top(); pq.pop();
            long long mx = pq.top(); pq.pop();
            pq.push(mn * 2 + mx);
        }

        return ret;
    }
};
