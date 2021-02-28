class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int lft = 0, rht = height.size() - 1;
        while (lft < rht) {
            int h = min(height[lft], height[rht]);
            area = max(area, (rht - lft) * h);
            
            while (lft < rht && height[lft] <= h) {
                ++lft;
            }
            while (lft < rht && height[rht] <= h) {
                --rht;
            }
        }

        return area;
    }
};