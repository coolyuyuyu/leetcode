class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        for (int i = 0, n = s.size(), j = 0, cnt = 0; i < n; ++i) {
            cnt += (s[i] == '1' ? +1 : -1);
            if (cnt == 0) {
                parts.push_back("1" + makeLargestSpecial(s.substr(j + 1, (i - 1) - (j + 1) + 1)) + "0");
                j = i + 1;
            }
        }
        std::sort(parts.begin(), parts.end(), std::greater<string>());

        string ret;
        for (const string& part : parts) {
            ret += part;
        }

        return ret;
    }
};
