class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, extra = 0;
        for (char c : moves) {
            switch (c) {
                case 'U':
                    ++y;
                    break;
                case 'D':
                    --y;
                    break;
                case 'L':
                    --x;
                    break;
                case 'R':
                    ++x;
                    break;
                case '_':
                    ++extra;
                    break;
            }
        }

        return std::abs(x) + std::abs(y) + extra;
    }
};
