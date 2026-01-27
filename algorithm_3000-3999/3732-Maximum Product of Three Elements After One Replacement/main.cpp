class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int mx1 = 0, mx2 = 0;
        for (int num : nums) {
            num = std::abs(num);
            if (num >= mx1) {
                mx2 = mx1;
                mx1 = num;
            }
            else if (num > mx2) {
                mx2 = num;
            }
        }

        return 1e5 * mx1 * mx2;
    }
};
