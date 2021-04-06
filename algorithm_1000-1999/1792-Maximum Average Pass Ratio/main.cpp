class Solution {
public:
    typedef pair<int, int> Class;

    static double passRate(int pass, int total) {
        return (static_cast<double>(pass) / total);
    };

    static double passRate(const Class& c) {
        return passRate(c.first, c.second);
    };

    static double benefit(const Class& c) {
        return (passRate(c.first + 1, c.second + 1) - passRate(c));
    };

    double maxAverageRatio_Heap(vector<vector<int>>& classes, int extraStudents) {
        auto comp = [&](const Class& c1, const Class& c2) {
            return (benefit(c1) < benefit(c2));

        };
        priority_queue<Class, vector<Class>, decltype(comp)> pq(comp); // max_heap
        for (const vector<int>& c : classes) {
            pq.emplace(c[0], c[1]);
        }

        for (size_t i = 0; i < extraStudents; ++i) {
            Class c = pq.top();
            pq.pop();
            pq.emplace(c.first + 1, c.second + 1);
        }


        double sum = 0;
        for (; !pq.empty(); pq.pop()) {
            sum += passRate(pq.top());
        }
        return (sum / classes.size());
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        return maxAverageRatio_Heap(classes, extraStudents);
    }
};