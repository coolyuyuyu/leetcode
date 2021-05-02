class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (const auto& item : items) {
            auto& pq = m[item[0]];
            if (5 <= pq.size()) {
                if (pq.top() < item[1]) {
                    pq.pop();
                    pq.push(item[1]);
                }
            }
            else {
                pq.push(item[1]);
            }
        }

        vector<vector<int>> results;
        for (auto& p : m) {
            auto& pq = p.second;
            assert(pq.size() == 5);

            int sum = 0;
            for (; !pq.empty(); pq.pop()) {
                sum += pq.top();
            }

            results.push_back({p.first, sum / 5});
        }

        return results;
    }
};
