class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> stk;
        for (size_t i = 0; i < num.size(); ++i) {
            while (!stk.empty() && num[i] < stk.back() && i < (stk.size() + k)) {
                stk.pop_back();
            }

            if (num.size() <= (stk.size() + k)) {
            }
            else {
                stk.push_back(num[i]);
            }
        }
        assert(num.size() == (stk.size() + k));

        while (!stk.empty() && stk.front() == '0') {
            stk.pop_front();
        }
        return (stk.begin() == stk.end() ? "0" : string(stk.begin(), stk.end()));
    }
};