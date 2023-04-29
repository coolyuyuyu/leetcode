class Solution {
public:
    string freqAlphabets(string s) {
        string ret;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if ((i + 2) < s.size() && s[i + 2] == '#') {
                    ret += (s[i + 1] - '0' + 'j');
                    i += 2;
                }
                else {
                    ret += 'a';
                }
            }
            else if (s[i] == '2') {
                if ((i + 2) < s.size() && s[i + 2] == '#') {
                    ret += (s[i + 1] - '0' + 't');
                    i+=2;
                }
                else {
                    ret += 'b';
                }
            }
            else if ('3' <= s[i] && s[i] <= '9') {
                ret += (s[i] - '1' + 'a');
            }
            else {
                assert(false);
            }
        }

        return ret;
    }
};
