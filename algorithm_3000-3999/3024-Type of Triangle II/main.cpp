class Solution {
public:
    string triangleType(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b <= c) {
            return "none";
        }
        if (a == b && b == c) {
            return "equilateral";
        }
        else if (a == b || b == c) {
            return "isosceles";
        }
        else {
            return "scalene";
        }
    }
};
