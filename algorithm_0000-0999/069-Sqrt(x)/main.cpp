class Solution {
public:
    int mySqrt(int x) {
        // Newton's method
        long int root = x;
        while (root * root > x) {
            root = (root + x / root) / 2;
        }

        return root;
    }
};