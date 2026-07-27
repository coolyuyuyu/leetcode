class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        string ret;
        vector<bool> inRet(26, false);
        for (char c : s) {
            --cnts[c - 'a'];
            if (!inRet[c - 'a']) {
                while (!ret.empty() && ret.back() > c && cnts[ret.back() - 'a']) {
                    inRet[ret.back() - 'a'] = false;
                    ret.pop_back();
                }

                ret += c;
                inRet[c - 'a'] = true;
            }
        } 

        return ret;
    }
};
