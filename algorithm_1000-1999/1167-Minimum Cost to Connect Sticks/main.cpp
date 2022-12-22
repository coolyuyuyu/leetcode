class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int stick : sticks) {
            pq.push(stick);
        }

        int ret = 0;
        while (2 <=  pq.size()) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            int z = x + y;
            pq.push(z);
            ret += (z);
        }

        return ret;
    }
};
