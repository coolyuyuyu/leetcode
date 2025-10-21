class Solution {
public:
    // Time: O(N)
    int maxArea(vector<int>& height) {
        int ret = 0;
        for (int l = 0, r = height.size() - 1; l < r;) {
            ret = std::max(ret, (r - l) * std::min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }

        return ret;    
    }
};
