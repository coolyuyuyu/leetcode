class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        long long pre = 0, ret = -1;
        for (int num : nums) {
            if (num < pre) {
                ret = pre + num;
            }
            pre += num;
        }

        return ret;
    }
};
