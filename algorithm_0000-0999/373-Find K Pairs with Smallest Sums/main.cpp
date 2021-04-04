class Solution {
public:
    vector<vector<int>> kSmallestPairs_Heap(vector<int>& nums1, vector<int>& nums2, size_t k) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return ((p1.first + p1.second) < (p2.first + p2.second));
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp); // max_heap
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                if (pq.size() < k) {
                    pq.emplace(num1, num2);
                }
                else if (comp({num1, num2}, pq.top())) {
                    pq.pop();
                    pq.emplace(num1, num2);
                }
                else {
                    break;
                }
            }
        }

        vector<vector<int>> ret;
        for (; !pq.empty(); pq.pop()) {
            ret.push_back({pq.top().first, pq.top().second});
        }
        return ret;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, size_t k) {
        return kSmallestPairs_Heap(nums1, nums2, k);
    }
};