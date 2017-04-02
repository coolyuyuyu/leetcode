class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t end = s.find_last_not_of(' ');
        if (end != string::npos) {
            size_t bgn = s.find_last_of(' ', end);
            if (bgn == string::npos) {
                return end + 1;
            }
            else {
                return end - bgn;
            }
        }
        else {
            return 0;
        }
    }
};