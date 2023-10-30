class Solution {
public:
    string largestOddNumber(string num) {
        size_t rht = num.find_last_of("13579");
        return rht == string::npos ? "" : num.substr(0, rht + 1);
    }
};
