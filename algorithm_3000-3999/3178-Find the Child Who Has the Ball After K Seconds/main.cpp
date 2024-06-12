class Solution {
public:
    int numberOfChild(int n, int k) {
        k = k % (n * 2 - 2);
        return k < n ? k : (n * 2 - 2 - k);
    }
};
