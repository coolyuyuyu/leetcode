class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end()); // max_heap
        while (1 < pq.size()) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int diff = x - y;
            if (0 < diff) {
                pq.push(diff);
            }
        }

        return (pq.empty() ? 0 : pq.top());
    }
};