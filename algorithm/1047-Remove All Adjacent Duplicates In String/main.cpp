class Solution {
public:
    string removeDuplicates_Stack(string S) {
        stack<char> stk;
        for (char c : S) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
            }
            else {
                stk.emplace(c);
            }
        }

        S.resize(stk.size());
        for (size_t i = S.size(); 0 < i--;) {
            S[i] = stk.top();
            stk.pop();
        }

        return S;
    }

    string removeDuplicates(string S) {
        return removeDuplicates_Stack(S);
    }
};