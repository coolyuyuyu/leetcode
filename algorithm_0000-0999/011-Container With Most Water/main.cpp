class Solution {
public:
    // two pointer
    // Time: O(n)
    int maxArea(vector<int>& height) {
        int ret = 0;
        for (int lft = 0, rht = height.size() - 1; lft < rht;) {
            ret = std::max(ret, (rht - lft) * std::min(height[lft], height[rht]));
            if (height[lft] <= height[rht]) {
                ++lft;
            }
            else {
                --rht;
            }
        }

        return ret;
    }
};
