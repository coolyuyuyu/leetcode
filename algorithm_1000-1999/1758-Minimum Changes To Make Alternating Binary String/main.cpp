class Solution {
public:
    int minOperations(string s) {
        int numOp1 = 0; // 010101...
        int numOp2 = 0; // 101010...
        for (size_t i = 0; i < s.size(); ++i) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    ++numOp1;
                }
                else {
                    ++numOp2;
                }
            }
            else {
                if (s[i] == '0') {
                    ++numOp1;
                }
                else {
                    ++numOp2;
                }
            }
        }

        return min(numOp1, numOp2);
    }
};
