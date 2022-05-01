class Solution {
public:
    string truncateSentence(string s, int k) {
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && --k == 0) {
                s.erase(i);
                break;
            }
        }

        return s;
    }
};
