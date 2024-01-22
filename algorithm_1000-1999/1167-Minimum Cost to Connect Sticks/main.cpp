class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int stick : sticks) {
            pq.push(stick);
        }

        int ret = 0;
        while (pq.size() >= 2) {
            int stick1 = pq.top(); pq.pop();
            int stick2 = pq.top(); pq.pop();
            int cost = stick1 + stick2;
            pq.push(cost);
            ret += cost;
        }

        return ret;
    }
};
