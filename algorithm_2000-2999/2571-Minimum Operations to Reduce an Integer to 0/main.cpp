class Solution {
public:
    int minOperations(int n) {
        vector<bool> flags;
        while (n) {
            flags.push_back(n & 1);
            n /= 2;
        }

        int ret = 0;
        int count = 0;
        for (int i = 0; i <= flags.size(); ++i) {
            if (i == flags.size() || flags[i] == false) {
                if (count > 1) {
                    ret += 1;
                    count = 1;
                }
                else if (count == 1) {
                    ret += 1;
                    count = 0;
                }
            }
            else {
                count++;
            }
        }
        if (count) {
            ret++;
        }

        return ret;
    }
};
