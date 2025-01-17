class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        for (int i = 2; s.size() < n; ++i) {
            char nxt = s.back() == '1' ? '2' : '1';
            if (s[i] == '1') {
                s.push_back(nxt);
            }
            else {
                s.push_back(nxt);
                s.push_back(nxt);
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ret;
            }
        }

        return ret;
    }
};
