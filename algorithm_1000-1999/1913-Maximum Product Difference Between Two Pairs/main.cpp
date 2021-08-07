class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a(10001), b(10001), c(0), d(0);
        for (int num : nums) {
            if (num < a) {
                b = a;
                a = num;
            }
            else if (num < b) {
                b = num;
            }

            if (d < num) {
                c = d;
                d = num;
            }
            else if (c < num) {
                c = num;
            }
        }

        return (c * d - a * b);
    }
};
