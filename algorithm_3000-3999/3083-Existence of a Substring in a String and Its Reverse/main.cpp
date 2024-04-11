class Solution {
public:
    bool isSubstringPresent(string s) {
        string t(s.rbegin(), s.rend());
        for (int i = 0; i + 1 < s.size(); ++i) {
            string ss = s.substr(i, 2);
            if (t.find(ss) != string::npos) {
                return true;
            }
        }

        return false;
    }
};
