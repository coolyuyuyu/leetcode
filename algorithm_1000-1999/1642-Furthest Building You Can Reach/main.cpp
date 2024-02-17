class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        priority_queue<int, vector<int>, std::greater<int>> pq;
        int sumBricks = 0;
        for (int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0) {
                continue;
            }

            pq.push(diff);
            if (pq.size() > ladders) {
                sumBricks += pq.top();
                pq.pop();
            }

            if (sumBricks > bricks) {
                return i - 1;
            }
        }

        return n - 1;
    }
};
