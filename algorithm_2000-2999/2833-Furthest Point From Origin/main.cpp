class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int empty = 0;
        int pos = 0;
        for (char c : moves) {
            if (c == 'L') {
                pos -= 1;
            }
            else if (c == 'R') {
                pos += 1;
            }
            else {
                empty += 1;
            }
        }

        return std::abs(pos) + empty;
    }
};
