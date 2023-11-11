class Solution {
public:
    bool isThree(int n) {
        if (n == 1) { return false; }

        int root = std::sqrt(n);
        if (root * root != n) {
            return false;
        }

        for (int i = 2; i < root; ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
};
