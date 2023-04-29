/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        int sameCnt = 1;
        int n = reader.length(), diffIdx;

        if (reader.query(0, 2, 3, 4) == reader.query(1, 2, 3, 4)) { // chck 0 1
            ++sameCnt;
        }
        else {
            diffIdx = 1;
        }
        if (reader.query(0, 1, 3, 4) == reader.query(1, 2, 3, 4)) { // chck 0 2
            ++sameCnt;
        }
        else {
            diffIdx = 2;
        }
        if (reader.query(0, 1, 2, 4) == reader.query(1, 2, 3, 4)) { // chck 0 3
            ++sameCnt;
        }
        else {
            diffIdx = 3;
        }

        for (int i = 4; i < n; ++i) {
            if (reader.query(0, 1, 2, 3) == reader.query(1, 2, 3, i)) {
                sameCnt += 1;
            }
            else {
                diffIdx = i;
            }
        }

        if ((n % 2) == 0 && (n / 2) == sameCnt) {
            return -1;
        }
        if ((n - sameCnt) <= sameCnt) {
            return 0;
        }
        else {
            return diffIdx;
        }
    }
};
