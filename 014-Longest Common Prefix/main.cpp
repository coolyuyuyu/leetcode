class Solution {
public:
    string longestCommonPrefix(const string& lft, const string& rht) {
        int len = 0;
        while (len < lft.size() && len < rht.size()) {
            if (lft[len] != rht[len]) {
                break;
            }
            ++len;
        }
        return lft.substr(0, len);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        else {
            string lcp = strs[0];
            for (int i = 1; i < strs.size(); ++i) {
                lcp = longestCommonPrefix(lcp, strs[i]);
            }
            return lcp;
        }
    }
};