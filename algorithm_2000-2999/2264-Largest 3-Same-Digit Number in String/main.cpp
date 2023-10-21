class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int ret = -1;
        for (int i = 0; i + 2 < n; ++i) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                ret = std::max(ret, num[i] - '0');
            }
        }

        if (ret == -1) {
            return "";
        }
        else {
            return string(3, '0' + ret);
        }
    }
};
