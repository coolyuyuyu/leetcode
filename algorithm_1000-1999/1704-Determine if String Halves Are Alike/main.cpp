class Solution {
public:
    bool halvesAreAlike(string s) {
        std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        auto countVowel = [&vowels](string::const_iterator bgn, string::const_iterator end) {
            int cnt = 0;
            for (auto itr = bgn; itr != end; ++itr) {
                char c = tolower(*itr);
                if (vowels.find(c) != vowels.end()) {
                    ++cnt;
                }
            }
            return cnt;
        };

        return countVowel(s.begin(), s.begin() + s.size() / 2) == countVowel(s.begin() + s.size() / 2, s.end());
    }
};
