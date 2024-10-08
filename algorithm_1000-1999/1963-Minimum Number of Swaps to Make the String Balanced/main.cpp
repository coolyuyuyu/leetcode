class Solution {
public:
    int minSwaps(string s) {
        int mismatchOpen = 0;
        for (char c : s) {
            if (c == '[') {
                ++mismatchOpen;
            }
            else {
                --mismatchOpen;
                if (mismatchOpen < 0) {
                    mismatchOpen = 0;
                }
            }
        }

        return (mismatchOpen + 1) / 2;
    }
};

// ][ => [] => 1
// ]][[ => [][] => 1
// ]]][[[ => []][][ => [[][]] => 2
// ]]]][[[[ => []]][[[] => [][][][] => 2
