class Solution {
public:
    inline void reverse(vector<char>& str, size_t first, size_t last) {
        while (first + 1 < last) {
            swap(str[first], str[last - 1]);
            ++first, --last;
        }
    }

    void reverseWords(vector<char>& str) {
        reverse(str, 0, str.size());

        size_t nonSpaceStart = 0;
        for (size_t i = 0; i <= str.size(); ++i) {
            if (str.size() <= i || isblank(str[i])) {
                reverse(str, nonSpaceStart, i);
                nonSpaceStart = i + 1;
            }
        }
    }
};