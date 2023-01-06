class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int cost : costs) {
            pq.push(cost);
        }

        int ret = 0;
        for (int sum = 0; !pq.empty() && (sum + pq.top()) <= coins; sum += pq.top(), pq.pop()) {
            ++ret;
        }

        return ret;
    }
};
