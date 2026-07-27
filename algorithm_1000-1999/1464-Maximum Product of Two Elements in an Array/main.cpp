class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sorted: ..., max2, max1
        int max2 = INT_MIN, max1 = INT_MIN;
        for (int num : nums) {
            if (num >= max1) {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max2 = num;
            }
        }

        return (max2 - 1) * (max1 - 1);
    }
};
