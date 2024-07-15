class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();

        string ret(n, '\0');
        for (int i = 0; i < n; ++i) {
            ret[i] = s[(i + k) % n];
        }

        return ret;
    }
};
