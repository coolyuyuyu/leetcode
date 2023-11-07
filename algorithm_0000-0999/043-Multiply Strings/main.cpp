class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();

        string ret(m + n, '0');
        for (int i = m; 0 < i--;) {
            for (int j = n; 0 < j--;) {
                int num = (num1[i] - '0') * (num2[j] - '0');
                ret[i + j + 1] += num % 10;
                ret[i + j] += num / 10;
                ret[i + j] += (ret[i + j + 1] - '0') / 10;
                ret[i + j + 1] = '0' + ((ret[i + j + 1] - '0') % 10);
            }
        }
        auto itr = std::find_if(ret.begin(), ret.end() - 1, [](char c){ return c != '0'; });
        return string(itr, ret.end());
    }
};
