class Solution {
public:
    vector<int> topKFrequent_Heap(vector<int>& nums, int k) {
        unordered_map<int, int> counts; // <num, frequency>
        for (int num : nums) {
            ++counts[num];
        }

        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
            return (p1.second > p2.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp); // min_heap
        for (const pair<int, int>& p : counts) {
            if (pq.size() < k) {
                pq.push(p);
            }
            else if (comp(p, pq.top())) {
                pq.pop();
                pq.push(p);
            }
        }

        vector<int> ret;
        for (; !pq.empty(); pq.pop()) {
            ret.push_back(pq.top().first);
        }
        return ret;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        return topKFrequent_Heap(nums, k);
    }
};