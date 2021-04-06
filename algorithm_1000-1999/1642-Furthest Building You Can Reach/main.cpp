class Solution {
public:
    int furthestBuilding_Heap(vector<int>& heights, int bricks, int ladders) {
        long sumBricks = 0;
        long sumBricksByLadder = 0;
        priority_queue<long, vector<long>, greater<long>> pq; // min_heap stores top "laddeers" differnces

        size_t i = 1;
        for (; i < heights.size(); ++i) {
            long diff = heights[i] - heights[i - 1];
            if (diff <= 0) {
                continue;
            }

            sumBricks += diff;
            if (pq.size() < ladders) {
                sumBricksByLadder += diff;

                pq.push(diff);
            }
            else if (!pq.empty() && pq.top() < diff) {
                sumBricksByLadder -= pq.top();
                sumBricksByLadder += diff;

                pq.pop();
                pq.push(diff);
            }

            if (bricks < (sumBricks - sumBricksByLadder)) {
                break;
            }
        }

        return (i - 1);
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return furthestBuilding_Heap(heights, bricks, ladders);
    }
};