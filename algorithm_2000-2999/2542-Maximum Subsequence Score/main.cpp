class Solution {
public:
    // Time: O(NlogN + NlogK)
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        size_t n = nums1.size();

        vector<pair<int, int>> pairs(n);
        for (size_t i = 0; i < n; ++i) {
            pairs[i] = {nums1[i], nums2[i];
        }
        std::sort(pairs.begin(), pairs.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second; });

        long long ret = 0, sum = 0;
        priority_queue<int, vector<int>, greater<>> pq; // min_heap
        for (size_t i = n; 0 < i--;) {
            sum += pairs[i].first;
            pq.push(pairs[i].first);
            if (k < pq.size()) {
                sum -= pq.top();
                pq.pop();
            }
            if (k == pq.size()) {
                ret = std::max(ret, sum * pairs[i].second);
            }
        }

        return ret;
    }
};
