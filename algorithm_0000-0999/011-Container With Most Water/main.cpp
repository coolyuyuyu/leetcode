class Solution {
public:
    // two pointer, Time: O(n)
    int maxArea(vector<int>& height) {
        size_t ans = 0;
        for (size_t lft = 0, rht = height.size() - 1; lft < rht;) {
            size_t h = std::min(height[lft], height[rht]);
            size_t area = h * (rht - lft);
            if (ans < area) {
                ans = area;
            }

            while (lft < rht && height[lft] <= h) {
                ++lft;
            }
            while (lft < rht && height[rht] <= h) {
                --rht;
            }
        }

        return ans;
    }
};