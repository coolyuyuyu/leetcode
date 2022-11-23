class Solution {
public:
    bool isStrobogrammatic(string num) {
        assert(!num.empty());

        string m = "01....9.86";
        for(size_t i = 0; (i * 2) <= num.size(); ++i) {
            if (m[num[i] - '0'] != num[num.size() - i - 1]) {
                    return false;
            }
        }

        return true;
    }
};
