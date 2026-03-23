class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int x = 0, y = 0;
        for (int num : nums) {
            if (num >= 10) {
                y += num;
            }
            else {
                x += num;
            }
        }

        return x != y;
    }
};
