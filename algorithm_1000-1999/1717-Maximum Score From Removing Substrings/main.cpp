class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            std::reverse(s.begin(), s.end());
            std::swap(x, y);
        }

        int ret = 0;

        string t;
        for (char c : s) {
            if (c == 'b' && !t.empty() && t.back() == 'a') {
                t.pop_back();
                ret += x;
            }
            else {
                t.push_back(c);
            }
        }

        string u;
        for (char c : t) {
            if (c == 'a' && !u.empty() && u.back() == 'b') {
                u.pop_back();
                ret += y;
            }
            else {
                u.push_back(c);
            }
        }

        return ret;
    }
};
