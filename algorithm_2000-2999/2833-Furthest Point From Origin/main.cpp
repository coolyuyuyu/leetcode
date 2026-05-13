class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ret = 0, empty = 0;
        for (char move : moves) {
            switch (move) {
                case 'L':
                    --ret;
                    break;
                case 'R':
                    ++ret;
                    break;
                case '_':
                    ++empty;
                    break;
            }
        }

        return std::abs(ret) + empty;
    }
};
