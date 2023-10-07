class Solution {
public:
    string removeVowels(string s) {
        string ret;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { continue; }
            ret += c;
        }

        return ret;
    }
};
