class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int coin : coins) {
            pq.push(coin);
        }

        int limit = 0;
        while (!pq.empty() && limit +1 >= pq.top()) {
            int coin = pq.top();
            pq.pop();

            limit += coin;
        }

        return limit + 1;
    }
};
