class Solution {
public:
    string reverseVowels(string s) {
        int lft = 0;
        int rht = s.size() - 1;
        while (lft < rht) {
            size_t lftVowel = s.find_first_of("aeiouAEIOU", lft);
            if (lftVowel == string::npos) {
                break;
            }
            lft = lftVowel;
            
            size_t rhtVowel = s.find_last_of("aeiouAEIOU", rht);
            if (rhtVowel == string::npos) {
                break;
            }
            rht = rhtVowel;

            if (lft < rht) {
                swap(s[lft++], s[rht--]);
            }
        }
        return s;
    }
};