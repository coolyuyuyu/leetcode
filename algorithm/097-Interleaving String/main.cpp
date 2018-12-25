class Solution {
public:
    bool isInterleaveRecv(const string& s1, size_t i1, const string& s2, size_t i2, const string& s3, size_t i3) {
        if (s3.size() <= i3) {
            if (s1.size() <= i1 && s2.size() <= i2) {
                return true;
            }
            else {
                return false;
            }
        }

        if (i1 < s1.size() && s1[i1] == s3[i3]) {
            if (isInterleaveRecv(s1, i1 + 1, s2, i2, s3, i3 + 1)) {
                return true;
            }
        }
        if (i2 < s2.size() && s2[i2] == s3[i3]) {
            if (isInterleaveRecv(s1, i1, s2, i2 + 1, s3, i3 + 1)) {
                return true;
            }
        }

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        return isInterleaveRecv(s1, 0, s2, 0, s3, 0);
    }
};