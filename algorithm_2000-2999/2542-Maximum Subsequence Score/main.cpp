class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        size_t n = nums1.size();

        vector<pair<int, int>> pairs(n);
        for (size_t i = 0; i < n; ++i) {
            pairs[i] = {nums1[i], nums2[i]};
        }
        std::sort(pairs.rbegin(), pairs.rend(), [](const auto& p1, const auto& p2) { return p1.second < p2.second; });

        long long sum = 0, ret = 0;
        priority_queue<int, vector<int>, greater<>> pq; // min_heap
        for (size_t i = 0; i < n; ++i) {
            if (k <= i) {
                sum -= pq.top();
                pq.pop();
            }
            sum += pairs[i].first;
            pq.push(pairs[i].first);

            if (pq.size() == k) {
                ret = std::max(ret, sum * pairs[i].second);
            }
        }

        return ret;
    }
};
