class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnts(10, 0);
        for (char d : num) {
            ++cnts[d - '0'];
        }
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] - '0' != cnts[i]) {
                return false;
            }
        }

        return true;
    }
};
