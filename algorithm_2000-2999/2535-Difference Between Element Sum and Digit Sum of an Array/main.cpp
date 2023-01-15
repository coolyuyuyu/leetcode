class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int esum = 0;
        int dsum = 0;
        for (int num : nums) {
            esum += num;

            while (num) {
                dsum += (num % 10);
                num /= 10;
            }
        }

        return abs(esum - dsum);
    }
};
