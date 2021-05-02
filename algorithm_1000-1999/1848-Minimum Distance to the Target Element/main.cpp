class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int dist = 0;
        for (; 0 <= (start - dist) || (start + dist) < nums.size(); ++dist) {
            if (0 <= (start - dist)) {
                if (nums[start - dist] == target) {
                    break;
                }
            }
            if ((start + dist) < nums.size()) {
                if (nums[start + dist] == target) {
                    break;
                }
            }
        }

        return dist;
    }
};
