class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        std::function<bool(const pair<int, int>&, const pair<int, int>&)> comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            const auto& [pass1, total1] = p1;
            const auto& [pass2, total2] = p2;
            return (1.0 * (pass1 + 1) / (total1 + 1)) - (1.0 * pass1 / total1) < (1.0 * (pass2 + 1) / (total2 + 1)) - (1.0 * pass2 / total2);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            pq.emplace(pass, total);
        }

        double sum = 0.0;
        for (int i = 0; i < extraStudents; ++i) {
            auto [pass, total] = pq.top();
            pq.pop();
            pq.emplace(pass + 1, total + 1);
        }

        for (; !pq.empty(); pq.pop()) {
            const auto& [pass, total] = pq.top();
            sum += 1.0 * pass / total;
        }

        return sum / classes.size();
    }
};
