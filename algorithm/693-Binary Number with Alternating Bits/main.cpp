class Solution {
public:
    bool hasAlternatingBits_v0(int n) {
        bool prevFlag = n % 2;
        n >>= 1;
        while (n) {
            bool flag = n % 2;
            if (prevFlag == flag) {
                return false;
            }
            
            n >>= 1;
            prevFlag = flag;
        }
        
        return true;
    }
    
    bool hasAlternatingBits_v1(int n) {        
        n = n ^ (n >> 2);        
        return (n & (n - 1)) == 0;
    }
    
    bool hasAlternatingBits(int n) {        
        return hasAlternatingBits_v1(n);
    }
};
