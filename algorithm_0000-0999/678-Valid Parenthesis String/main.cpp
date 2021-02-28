class Solution {
public:
    // Time(n): O(3^n), TLE
    bool checkValidStringDfs(const string& str, size_t pos, size_t openCount) {
        for (size_t i = pos; i < str.size(); ++i) {
            switch (str[i]) {
                case '(':
                    ++openCount;
                    break;
                case ')':
                    if (openCount == 0) {
                        return false;
                    }
                    --openCount;
                    break;
                case '*':
                    if (checkValidStringDfs(str, pos + 1, openCount + 1)) {
                        return true;
                    }
                    if (1 <= openCount && checkValidStringDfs(str, pos + 1, openCount - 1)) {
                        return true;
                    }
                    break;
            }
        }

        return openCount == 0;
    }

    bool checkValidStringGreedy(const string& str) {
        size_t openCountLower = 0, openCountUpper = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            switch (str[i]) {
                case '(':
                    ++openCountLower;
                    ++openCountUpper;
                    break;
                case ')':
                    if (0 < openCountLower) {
                        --openCountLower;
                    }

                    if (openCountUpper == 0) {
                        return false;
                    }
                    --openCountUpper;
                    break;
                case '*':
                    if (0 < openCountLower) {
                        --openCountLower;
                    }

                    ++openCountUpper;
                    break;
            }
        }

        return openCountLower == 0;
    }

    bool checkValidString(const string& str) {
        //return checkValidStringDfs(str, 0, 0);

        return checkValidStringGreedy(str);
    }
};