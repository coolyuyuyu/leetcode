class Solution {
public:
    int scan_after_count(const string& s) {
        vector<int> cnts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++cnts[s[i] - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (cnts[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    int scan_while_count(const string& s) {
        vector<int> cnts(26, 0);
        int slow = 0, fast = 0;
        while (fast < s.size()) {
            ++cnts[s[fast++] - 'a'];
            while (slow < fast && 1 < cnts[s[slow] - 'a']) {
                ++slow;
            }
        }

        return (slow == s.size() ? -1 : slow);
    }

    int firstUniqChar(string s) {
        //return scan_after_count(s);
        return scan_while_count(s);
    }
};
