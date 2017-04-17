class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;
        for (char c: s) {
            switch (c) {
            case 'A':
                ++absent;
                if (2 <= absent) {
                    return false;
                }
                late = 0;
                break;
            case 'L':
                ++late;
                if (3 <=late) {
                    return false;
                }
                break;
            case 'P':
                late = 0;
                break;
            default:
                assert(false);
                break;
            }
        }

        return true;
    }
};