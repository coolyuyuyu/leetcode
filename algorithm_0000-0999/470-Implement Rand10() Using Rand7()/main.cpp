// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int f1() {
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

    int f2() {
        int num = rand7() - 1;
        do {
            num %= 49;
            num = num * 7 + rand7() - 1;
        } while (num >= 40);

        return num % 10 + 1;
    }

    std::vector<int> m_nums;
    int f3() {
        if (m_nums.empty()) {
            int num = 0;
            for (int i = 0; i < 6; ++i) {
                num = num * 7 + rand7() - 1;
            }
            do {
                num %= 823543;
                num = num * 7 + rand7() - 1;
            } while (num >= 800000);

            for (int i = 0; i < 5; ++i, num /= 10) {
                m_nums.push_back(num % 10 + 1);
            }
        }

        int ret = m_nums.back();
        m_nums.pop_back();
        return ret;
    }

    int rand10() {
        //return f1();
        //return f2();
        return f3();
    }
};
