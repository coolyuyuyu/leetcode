class Solution {
public:
    int minInsertions(string s) {
        int num = 0;

        int open = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++open;
            }
            else {
                if (open == 0) {
                    ++num;
                }
                else {
                    --open;
                }

                if ((i + 1) < s.size() && s[i + 1] == ')') {
                    ++i;
                }
                else {
                    ++num;
                }
            }
        }

        return (num + open * 2);
    }
};