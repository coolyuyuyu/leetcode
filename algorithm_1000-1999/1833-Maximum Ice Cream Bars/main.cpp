class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int cost : costs) {
            pq.push(cost);
        }

        int ret = 0;
        while (!pq.empty() && coins >= pq.top()) {
            coins -= pq.top();
            pq.pop();
            ++ret;
        }

        return ret;
    }
};
