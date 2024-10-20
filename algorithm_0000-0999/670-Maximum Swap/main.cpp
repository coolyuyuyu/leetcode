class Solution {
public:
    int maximumSwap(int num) {
        string s = std::to_string(num);
        int n = s.size();

        string t = s;
        std::sort(t.rbegin(), t.rend());

        int i = 0;
        for (i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                break;
            }
        }
        if (i == n) { return num; }

        int j;
        for (int pos = i + 1; pos < n; ++pos) {
            if (s[pos] == t[i]) {
                j = pos;
            }
        }

        std::swap(s[i], s[j]);

        return std::stoi(s);
    }
};
