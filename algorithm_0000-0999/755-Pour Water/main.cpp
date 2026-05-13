class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        stack<int> lftStk, rhtStk;
        for (int lftEnd = k, rhtEnd = k; volume > 0; --volume) {
            for (; lftEnd > 0 && heights[lftEnd - 1] <= heights[lftEnd]; --lftEnd) {
                if (heights[lftEnd - 1] < heights[lftEnd]) {
                    lftStk.push(lftEnd - 1);
                }
            }
            for (; rhtEnd + 1 < heights.size() && heights[rhtEnd] >= heights[rhtEnd + 1]; ++rhtEnd) {
                if (heights[rhtEnd] > heights[rhtEnd + 1]) {
                    rhtStk.push(rhtEnd + 1);
                }
            }

            if (!lftStk.empty()) {
                auto lftFall = lftStk.top();
                ++heights[lftFall];
                if (heights[lftFall] == heights[lftFall + 1]) {
                    lftStk.pop();
                }
                if (lftEnd < lftFall) {
                    lftStk.push(lftFall - 1);
                }
            }
            else if (!rhtStk.empty()) {
                auto rhtFall = rhtStk.top();
                ++heights[rhtFall];
                if (heights[rhtFall - 1] == heights[rhtFall]) {
                    rhtStk.pop();
                }
                if (rhtFall < rhtEnd) {
                    rhtStk.push(rhtFall + 1);
                }
            }
            else {
                ++heights[k];
                if (k > lftEnd) {
                    lftStk.push(k - 1);
                }
                if (k < rhtEnd) {
                    rhtStk.push(k + 1);
                }
            }
        }

        return heights;
    }
};
