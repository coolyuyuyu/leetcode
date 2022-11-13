class Solution {
public:
    void reverse(string::iterator first, string::iterator last) {
        while (first != last && first != --last) {
            std::iter_swap(first++, last);
        }
    }

    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        auto itr = s.begin();
        for (auto itrFirst = s.begin(); itrFirst != s.end(); ) {
            itrFirst = std::find_if(itrFirst, s.end(), [](char c) { return !isblank(c); });
            if (itrFirst != s.end()) {
                auto itrLast = std::find_if(itrFirst, s.end(), [](char c) { return isblank(c); });
                reverse(itrFirst, itrLast);
                if (itr != s.begin()) {
                    *itr++ = ' ';
                }
                itr = std::copy(itrFirst, itrLast, itr);

                itrFirst = itrLast;
                if (itrFirst != s.end()) {
                    ++itrFirst;
                }
            }
        }
        s.erase(itr, s.end());

        return s;
    }
};
