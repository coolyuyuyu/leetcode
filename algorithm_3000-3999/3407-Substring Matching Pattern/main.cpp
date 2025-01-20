class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t sep = p.find('*');
        string s1 = p.substr(0, sep), s2 = p.substr(sep + 1);

        size_t idx1 = s.find(s1);
        if (idx1 == string::npos) {
            return false;
        }
        size_t idx2 = s.find(s2, idx1 + s1.size());
        return idx2 != string::npos;
    }
};
