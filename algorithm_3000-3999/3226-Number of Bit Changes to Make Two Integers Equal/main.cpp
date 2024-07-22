class Solution {
public:
    int minChanges(int n, int k) {
        int x = n ^ k;
        if ((x & k) != 0) {
            return -1;
        }
        else {
            return __builtin_popcount(x);
        }
    }
};
