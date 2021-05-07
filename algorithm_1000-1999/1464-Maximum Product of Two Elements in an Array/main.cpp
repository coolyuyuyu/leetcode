class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int val1 = numeric_limits<int>::min(), val2 = numeric_limits<int>::min();
        auto fn = [&val1, &val2](int num) {
            if (val1 < num) {
                val2 = val1;
                val1 = num;
            }
            else if (val2 < num) {
                val2 = num;
            }
        };
        for_each(nums.begin(), nums.end(), fn);

        return (val1 - 1) * (val2 - 1);
    }
};
