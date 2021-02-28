class Solution {
public:
    string toLowerCase(string str) {
        for (size_t i = 0; i < str.size(); ++i) {
            char c = str[i];
            if ('A'<= c && c <= 'Z') {
                str[i] = c - 'A' + 'a';
            }
        }

        //transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};