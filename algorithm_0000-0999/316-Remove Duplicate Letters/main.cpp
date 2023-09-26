class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        string stk;
        vector<bool> inStk(26, 0);
        for (char c : s) {
            if (inStk[c - 'a']) {
                --cnts[c - 'a'];
            }
            else {
                while (!stk.empty() && stk.back() > c && cnts[stk.back() - 'a'] > 0) {
                    inStk[stk.back() - 'a'] = false;
                    stk.pop_back();
                }
                --cnts[c - 'a'];

                stk.push_back(c);
                inStk[c - 'a'] = true;
            }
        }

        return stk;
    }
};
