class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;
        for (char c : num) {
            while (!stk.empty() && stk.back() > c && 0 < k--) {
                stk.pop_back();
            }
            stk.push_back(c);
        }
        while (0 < k--) {
            stk.pop_back();
        }

        auto pos = stk.find_first_not_of('0');
        if (pos != string::npos) {
            stk = stk.substr(pos);
        }
        else {
            stk.clear();
        }

        return stk.empty() ? "0" : stk;
    }
};
