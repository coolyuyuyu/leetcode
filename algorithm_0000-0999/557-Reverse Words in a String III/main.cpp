class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (isspace(s[i])) {
                continue;
            }

            auto itr = std::find_if(s.begin() + i + 1, s.end(), [](char c) { return isspace(c) != 0; } );
            std::reverse(s.begin() + i, itr);

            i = std::distance(s.begin(), itr);
        }

        return s;
    }
};
