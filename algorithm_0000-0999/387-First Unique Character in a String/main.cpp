class Solution {
public:
    int scan_after_count(const string& s) {
        int cnts[26];
        std::fill(cnts, cnts + 26, 0);

        for (char c : s) {
            ++cnts[c - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (cnts[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    int scan_while_count(const string& s) {
        int cnts[26];
        std::fill(cnts, cnts + 26, 0);

        int slow = 0, fast = 0;
        while (fast < s.size()) {
            ++cnts[s[fast++] - 'a'];
            while (slow < fast && cnts[s[slow] - 'a'] > 1) {
                ++slow;
            }
        }

        return slow < s.size() ? slow : -1;
    }

    int firstUniqChar(string s) {
        //return scan_after_count(s);
        return scan_while_count(s);
    }
};
