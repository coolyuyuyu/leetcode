class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        string stk;
        vector<bool> inStk(26, false);
        for (char c : s) {
            if (inStk[c - 'a'] == false) {
                while (!stk.empty() && stk.back() > c && cnts[stk.back() - 'a'] > 0) {
                    inStk[stk.back() - 'a'] = false;
                    stk.pop_back();
                }

                inStk[c - 'a'] = true;
                stk.push_back(c);
            }

            --cnts[c - 'a'];
        }

        return stk;
    }
};
