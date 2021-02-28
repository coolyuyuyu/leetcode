class Solution {
public:
    inline void reverse(string& str, size_t first, size_t last) {
        while (first + 1 < last) {
            swap(str[first], str[last - 1]);
            ++first, --last;
        }
    }

    void reverseWords(string &str) {
        reverse(str, 0, str.size());

        size_t nonSpaceStart = 0;
        for (size_t i = 0; i <= str.size(); ++i) {
            if (str.size() <= i || isblank(str[i])) {
                reverse(str, nonSpaceStart, i);
                nonSpaceStart = i + 1;
            }
        }

        size_t toRead = 0;
        size_t toWrite = 0;
        while (toRead < str.size()) {
            while (toRead < str.size() && isblank(str[toRead]))
                ++toRead;

            while (toRead < str.size() && !isblank(str[toRead])) {
                str[toWrite] = str[toRead];
                ++toWrite, ++toRead;
            }

            if (toWrite < str.size()) {
                str[toWrite++] = ' ';
            }
        }

        str.resize(toWrite);
        while (!str.empty() && isblank(str.back())) {
            str.pop_back();
        }
    }
};