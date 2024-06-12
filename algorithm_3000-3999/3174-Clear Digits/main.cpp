class Solution {
public:
    string clearDigits(string s) {
        string ret;
        for (char c : s) {
            if (isdigit(c)) {
                ret.pop_back();
            }
            else {
                ret.push_back(c);
            }
        }

        return ret;
    }
};
