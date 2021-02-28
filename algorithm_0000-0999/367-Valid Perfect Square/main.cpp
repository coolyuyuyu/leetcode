class Solution {
public:
    //bool isPerfectSquare(int num) {
    //    int n = 1;
    //    while (num > 0) {
    //        num -= n;
    //        n += 2;
    //    }
    //
    //    return num == 0;
    //}
    
    bool isPerfectSquare(int num) {
        long root = num;
        while (root * root > num) {
            root = (root + num / root) / 2;
        }
    
        return root * root == num;
    }
};