class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0, squreA = a * a; squreA <= c; ++a, squreA = a * a) {
            int squareB = c - squreA;
            
            int lft = 0, rht = squareB, target = squareB;
            while (lft <= rht) {
                int mid = lft + (rht - lft) / 2;
                long long val = (long long)mid * (long long)mid;
                if (val == target) {
                    return true;
                }
                else if (val < target) {
                    lft = mid + 1;
                }
                else {
                    rht = mid - 1;
                }                
            }
        }
        
        return false;
    }
};
