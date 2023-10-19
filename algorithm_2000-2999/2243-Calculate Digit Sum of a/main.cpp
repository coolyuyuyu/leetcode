class Solution {
public:
    string digitSum(string s, int k) {
        while (k < s.size()) {
            string tmp;
            int subsum = 0;
            for (int j = 0; j < s.size(); ++j) {
                subsum += s[j] - '0';
                if (((j + 1) % k) == 0 || s.size() <= j + 1) {
                    tmp += std::to_string(subsum);
                    subsum = 0;
                }
            }
            s = tmp;
        }

        return s;
    }
};
