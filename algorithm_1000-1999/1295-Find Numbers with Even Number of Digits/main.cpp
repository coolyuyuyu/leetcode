class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (10 <= num && num <= 99) {
                ++count;
            }
            else if (1000 <= num && num <= 9999) {
                ++count;
            }
            else if (num == 100000) {
                ++count;
            }
        }

        return count;
    }
};
