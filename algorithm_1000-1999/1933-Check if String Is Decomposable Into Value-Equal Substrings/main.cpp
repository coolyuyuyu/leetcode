class Solution {
public:
    bool isDecomposable(string s) {
        bool found2Once = false;
        for (size_t i = 0; i < s.size(); ) {
            size_t pos = s.find_first_not_of(s[i], i + 1);
            size_t len = pos == string::npos ? s.size() - i : pos - i;
            if (len == 2 || (2 <= len && (len - 2) % 3 == 0)) {
                if (found2Once) {
                    return false;
                }
                found2Once = true;
            }
            else if (len % 3 != 0) {

                return false;
            }
            i = pos;
        }

        return found2Once;
    }
};
