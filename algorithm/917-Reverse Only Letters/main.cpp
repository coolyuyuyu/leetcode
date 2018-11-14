class Solution {
public:
    string reverseOnlyLetters(string str) {
        if (str.empty()) {
            return str;
        }

        size_t i = 0;
        size_t j = str.size() - 1;

        while (i < j) {
            while (i < j && !isalpha(str.at(i))) {
                ++i;
            }

            while (i < j && !isalpha(str.at(j))) {
                --j;
            }

            if (i < j) {
                swap(str[i++], str[j--]);
            }
        
        }
        return str;
    }
};