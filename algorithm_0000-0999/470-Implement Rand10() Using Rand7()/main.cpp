// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int group;
        do {
            group = rand7();
        } while (group > 5);

        int parity;
        do {
            parity = rand7();
        } while (parity > 6);

        return (group - 1) * 2 + 1 + (parity & 1);
    }
};

/*
1 2 3 4 5 6 7

*/