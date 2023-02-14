class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }

        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool{
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp); // min_heap
        for (const pair<int, int>& p : freq) {
            pq.push(p);
            if (k < pq.size()) {
                pq.pop();
            }
        }

        vector<int> ret(k);
        for (int i = 0; i < k; ++i) {
            ret[i] = pq.top().first;
            pq.pop();
        }
        return ret;
    }
};
