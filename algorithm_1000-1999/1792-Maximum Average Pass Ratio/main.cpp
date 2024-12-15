class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        std::function<bool(const pair<int, int>&, const pair<int, int>&)> cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            const auto& [pass1, total1] = p1;
            const auto& [pass2, total2] = p2;
            return std::less<>()((1.0 * pass1 + 1) / (total1 + 1) - (1.0 * pass1 / total1), (1.0 * pass2 + 1) / (total2 + 1) - 1.0 * pass2 / total2);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (const auto& c : classes) {
            int pass = c[0], total = c[1];
            pq.emplace(pass, total);
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto [pass, total] = pq.top();
            pq.pop();
            pq.emplace(pass + 1, total + 1);
        }

        double sum = 0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            sum += (1.0 * pass / total);
        }

        return sum / classes.size();
    }
};
