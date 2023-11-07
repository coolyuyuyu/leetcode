class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        priority_queue<double, vector<double>, std::greater<double>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(1.0 * dist[i] / speed[i]);
        }

        for (int i = 0; !pq.empty(); ++i) {
            if (i >= pq.top()) {
                return i;
            }
            pq.pop();
        }

        return n;
    }
};
