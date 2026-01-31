class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ret = 0;
        for (int num = num1; num <= num2; ++num) {
            string s = std::to_string(num);
            for (int i = 1; i + 1 < s.size(); ++i) {
                if ((s[i - 1] < s[i] && s[i] > s[i + 1]) || (s[i - 1] > s[i] && s[i] < s[i + 1])) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
