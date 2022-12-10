class Solution {
public:
    int f(const string& str) {
        int num = 0;
        for (char c : str) {
            num *= 10;
            if (c < '0' || '9' < c) {
                return str.size();
            }
            else {
                num += (c - '0');
            }
        }

        return num;
    }

    int maximumValue(vector<string>& strs) {
        int ret = 0;
        for (const string& str : strs) {
            ret = std::max(ret, f(str));

        }
        return ret;
    }
};
