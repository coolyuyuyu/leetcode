class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // sorted: min1, min2, ... , max3, max2, max1
        int min1 = INT_MAX, min2 = INT_MAX, max3 = INT_MIN, max2 = INT_MIN, max1 = INT_MIN;
        for (int num : nums) {
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }

            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num >= max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }
        }

        return std::max(min1 * min2 * max1, max3 * max2 * max1);
    }
};
