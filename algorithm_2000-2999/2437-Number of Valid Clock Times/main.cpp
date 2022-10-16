class Solution {
public:
    int countTime(string time) {
        int c;
        if (time[0] == '?') {
            if (time[1] == '?') {
                c = 24;
            }
            else if ('4' <= time[1]) {
                c = 2;
            }
            else {
                c = 3;
            }
        }
        else {
            if (time[1] == '?') {
                if (time[0] == '2') {
                    c = 4;
                }
                else {
                    c = 10;
                }
            }
            else {
                c = 1;
            }
        }

        if (time[3] == '?') {
            c *= 6;
        }
        if (time[4] == '?') {
            c *= 10;
        }

        return c;
    }
};
