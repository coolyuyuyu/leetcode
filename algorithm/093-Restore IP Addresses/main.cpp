class Solution {
public:
    void restoreIpAddresses(const string& s, size_t index, size_t level, string& result, vector<string>& results) {
        if (level == 0) {
            results.emplace_back(result);
            return;
        }

        size_t len = s.size() - index;
        if (level * 3 < len || len < level) {
            return;
        }

        if (1 < level) {
            if (s[index] == '0') {
                result += "0.";
                restoreIpAddresses(s, index + 1, level - 1, result, results);
                result.resize(result.size() - 2);
            }
            else {
                string numStr;
                for (size_t i = 0, num = 0; i < 3; ++i) {
                    num = num * 10 + s[index + i] - '0';
                    if (255 < num) {
                        break;
                    }
                    numStr.push_back(s[index + i]);

                    result += (numStr + ".");
                    restoreIpAddresses(s, index + i + 1, level - 1, result, results);
                    result.resize(result.size() - i - 2);
                }
            }
        }
        else {
            if (len < 2 || s[index] != '0') {
                string numStr = s.substr(index);
                if (atoi(numStr.c_str()) <= 255) {
                    result += numStr;
                    restoreIpAddresses(s, s.size(), level - 1, result, results);
                    result.resize(result.size() - len);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string result;
        vector<string> results;
        restoreIpAddresses(s, 0, 4, result, results);
        return results;
    }
};