class Solution {
public:
    // greedy
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        for (; 0 < k; --k) {
            int stone = pq.top();
            pq.pop();

            pq.push(stone - stone / 2);
        }

        int ret = 0;
        while (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }

        return ret;
    }
};
