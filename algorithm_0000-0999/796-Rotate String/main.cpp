class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        std::function<bool(int)> f = [&](int i) {
            for (int cnt = 0; cnt < n; ++cnt, i = (i + 1) % n) {
                if (s[i] != goal[cnt]) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (f(i)) {
                return true;
            }
        }
        return false;
    }
};
