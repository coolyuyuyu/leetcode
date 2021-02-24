class Solution {
public:
    string removeDuplicates_Stack(string S) {
        stack<char> stk;
        for (char c : S) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }

        S.resize(stk.size());
        for (size_t i = S.size(); 0 < i--;) {
            S[i] = stk.top();
            stk.pop();
        }

        return S;
    }

    string removeDuplicates_Linear(string S) {
        string result;
        result.reserve(S.size());
        for (size_t i = 0; i < S.size(); ++i) {
            if (!result.empty() && S[i] == result.back()) {
                result.pop_back();
            }
            else {
                result.push_back(S[i]);
            }
        }

        return result;
    }

    string removeDuplicates(string S) {
        //return removeDuplicates_Stack(S);
        return removeDuplicates_Linear(S);
    }
};