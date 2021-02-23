class Solution {
public:
    string makeGood_Stack(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (!stk.empty() && abs(stk.top() - c) == 32)  {
                stk.pop();
            }
            else {
                stk.emplace(c);
            }
        }

        string result(stk.size(), '\0');
        for (size_t i = stk.size(); 0 < i--;) {
            result[i] = stk.top();
            stk.pop();
        }

        return result;
    }

    string makeGood(string s) {
        return makeGood_Stack(s);
    }
};