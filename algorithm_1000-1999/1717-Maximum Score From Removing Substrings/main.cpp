class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (y > x) {
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

        s = t;
        t.clear();
        for (char c : s) {
            if (c == 'a' && !t.empty() && t.back() == 'b') {
                t.pop_back();
                ret += y;
            }
            else {
                t.push_back(c);
            }
        }

        return ret;
    }
};
