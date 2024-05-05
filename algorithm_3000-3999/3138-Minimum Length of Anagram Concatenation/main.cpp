class Solution {
public:
    int minAnagramLength(string s) {
        std::function<bool(int)> check = [&](int len) {
            string ref = s.substr(0, len);
            std::sort(ref.begin(), ref.end());

            for (int i = len, n = s.size(); i < n; i += len) {
                string tmp = s.substr(i, len);
                std::sort(tmp.begin(), tmp.end());
                if (tmp != ref) {
                    return false;
                }
            }

            return true;
        };

        for (int len = 1, n = s.size(); len < n; ++len) {
            if (n % len != 0) { continue; }
            if (check(len)) {
                return len;
            }
        }

        return s.size();
    }
};
