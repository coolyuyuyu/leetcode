class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for (char c : s) {
            sum += (c - 'a' + 1);
        }

        int pre = 0;
        for (int c : s) {
            pre += (c - 'a' + 1);
            if (pre * 2 == sum) {
                return true;
            }
        }

        return false;
    }
};
