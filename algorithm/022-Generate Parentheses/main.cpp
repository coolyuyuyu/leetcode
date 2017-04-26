class Solution {
public:
    void generateParenthesisHelper(int n, int openCount, vector<string>& strs, string& str) {
        if (str.size() < (n * 2)) {
            if (openCount < n) {
                str.push_back('(');
                generateParenthesisHelper(n, openCount + 1, strs, str);
                str.pop_back();
            }

            if ((str.size() - openCount) < openCount) {
                str.push_back(')');
                generateParenthesisHelper(n, openCount, strs, str);
                str.pop_back();
            }
        }
        else {
            strs.push_back(str);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> strs;
        string str;
        generateParenthesisHelper(n, 0, strs, str);
        return strs;
    }
};