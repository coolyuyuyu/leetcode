class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();

        int turn = n - 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                turn = i - 1;
                break;
            }
        }
        if (turn == n - 1) {
            return 0;
        }

        for (int i = turn + 1; (i + 1) < n; ++i) {
            if (nums[i] > nums[i + 1]) {
                return -1;
            }
        }
        if (nums[n - 1] > nums[0]) {
            return -1;
        }

        return n - turn - 1;
    }
};
