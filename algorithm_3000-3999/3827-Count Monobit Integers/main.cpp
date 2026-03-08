class Solution {
public:
    int countMonobit(int n) {
        int ret = 0;
        for (int i = 0; pow(2,i) - 1 <= n; ++i) {
            ++ret;
        }

        return ret;
    }
};
