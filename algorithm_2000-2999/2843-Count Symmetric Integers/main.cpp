class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for (int num = low; num <= high; ++num) {
            string s = std::to_string(num);
            if (s.size() & 1) {
                continue;
            }

            int sum = 0;
            for (int i = 0; (i * 2) < s.size(); ++i) {
                sum += s[i];
                sum -= s[s.size() - i - 1];
            }
            if (sum == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
