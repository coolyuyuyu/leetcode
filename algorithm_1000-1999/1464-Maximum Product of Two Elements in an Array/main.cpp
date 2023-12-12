class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        for (int num : nums) {
            if (max1 < num) {
                max2 = max1;
                max1 = num;
            }
            else if (max2 < num) {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
