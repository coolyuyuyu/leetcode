class Solution {
public:
    string largestGoodInteger(string num) {
        char ret = '0' - 1;
        for (int i = 2; i < num.size();) {
            if (num[i - 2] == num[i - 1]) {
                if (num[i - 1] == num[i]) {
                    ret = std::max(ret, num[i]);
                    i += 3;
                }
                else {
                    i += 2;
                }
            }
            else {
                i += 1;
            }
        }

        return '0' <= ret ? string(3, ret) : "";
    }
};
