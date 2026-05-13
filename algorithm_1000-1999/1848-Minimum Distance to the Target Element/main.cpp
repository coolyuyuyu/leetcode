class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int lft = start, rht = start, n = nums.size(); lft >= 0 || rht < n; --lft, ++rht) {
            if (lft >= 0 && nums[lft] == target) { return start - lft; }
            if (rht < n && nums[rht] == target) { return rht - start; }
        }

        std::unreachable();
        return -1;
    }
};
