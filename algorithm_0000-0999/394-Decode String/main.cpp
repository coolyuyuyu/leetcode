class Solution {
public:
    string decodeString(string s) {
        stringstream ss;

        size_t index = 0;
        while (index < s.size()) {
            if (isalpha(s[index])) {
                ss << s[index];
                ++index;
            }
            else {
                int count = 0;
                while (isdigit(s[index])) {
                    count *= 10;
                    count += (s[index] - '0');
                    ++index;
                }
                assert(s[index] == '[');

                size_t bgn = ++index;
                size_t bracket = 1;
                while (bracket != 0) {
                    switch (s[index]) {
                    case '[':
                        ++bracket;
                        break;
                    case ']':
                        --bracket;
                        break;
                    }
                    ++index;
                }
                assert(s[index - 1] == ']');

                size_t end = index - 1;
                string decodeStr = decodeString(s.substr(bgn, end - bgn));
                for (int i = 0; i < count; ++i) {
                    ss << decodeStr;
                }
            }
        }

        return ss.str();
    }
};