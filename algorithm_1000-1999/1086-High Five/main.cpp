class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> id2top5;
        for (const auto& item : items) {
            int id = item[0], score = item[1];
            auto& top5 = id2top5[id];
            top5.push(score);
            if (top5.size() > 5) {
                top5.pop();
            }
        }

        vector<vector<int>> ret;
        for (auto& [id, top5] : id2top5) {
            int sum = 0;
            for (; !top5.empty(); top5.pop()) {
                sum += top5.top();
            }
            ret.push_back({id, sum / 5});
        }
        std::sort(ret.begin(), ret.end());

        return ret;
    }
};
