class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.size() % 2 != 0) {
            return false;
        }

        int x = 0;
        int y = 0;
        for (size_t i = 0; i < moves.size(); ++i) {
            switch (moves[i]) {
            case 'U':
                ++y;
                break;
            case 'R':
                ++x;
                break;
            case 'D':
                --y;
                break;
            case 'L':
                --x;
                break;
            }
        }

        return x == 0 && y == 0;
    }
};