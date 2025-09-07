class Solution {
public:
    int minSensors(int n, int m, int k) {
        int l = k * 2 + 1;
        return ((n + l - 1) / l) * ((m + l - 1) / l);
    }
};
