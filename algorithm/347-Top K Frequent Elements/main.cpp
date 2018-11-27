class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            ++counts[num];
        }

        typedef pair<int, int> NumCount;
        auto comp = [](const NumCount& lft, const NumCount& rht) { return lft.second > rht.second; };
        priority_queue<NumCount, vector<NumCount>, decltype(comp)> pq(comp);
        for (auto numCount : counts) {
            if (pq.size() < k) {
                pq.emplace(numCount.first, numCount.second);
            }
            else {
                if (comp(numCount, pq.top())) {
                    pq.pop();
                    pq.emplace(numCount.first, numCount.second);
                }
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            NumCount numCount = pq.top();
            pq.pop();

            ans.push_back(numCount.first);
        }
        return ans;
    }
};