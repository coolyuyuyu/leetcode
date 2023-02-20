class Solution {
public:
    int f1(int n) {
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

    int f2(int n) {
        int cnt = 0;
        for (int i = 0; i < 31; ++i) {
            if ((__builtin_popcount(n + (1 << i)) + 1) <= __builtin_popcount(n)) {
                n += (1 << i);
                ++cnt;
            }
        }

        return __builtin_popcount(n) + cnt;
    }

    int minOperations(int n) {
        return f1(n);
        //return f2(n);
    }
};
