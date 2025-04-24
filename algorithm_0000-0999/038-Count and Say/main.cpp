class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for (; 1 < n; --n) {
            string s;
            for (int i = 0, cnt = 0; i <= ret.size(); ++i) {
                if (i > 0 && (ret[i - 1] != ret[i] || i == ret.size())) {
                    s += std::to_string(cnt);
                    s += ret[i - 1];
                    cnt = 0;
                }
                ++cnt;
            }
            ret = s;
        }

        return ret;
    }
};
