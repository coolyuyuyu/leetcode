class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans(nums.size());

        auto quad = [&](int num) {
            return a * num * num + b * num + c;
        };

        size_t lft = 0, rht = nums.size();
        size_t index = (0 < a ? nums.size() : 0);
        while (lft < rht){
            if (0 < a) {
                ans[--index] = quad(nums[lft]) < quad(nums[rht - 1]) ? quad(nums[rht-- - 1]) : quad(nums[lft++]);
            }
            else {
                ans[index++] = quad(nums[lft]) < quad(nums[rht - 1]) ? quad(nums[lft++]) : quad(nums[rht-- - 1]);
            }
        }

        return ans;
    }
};