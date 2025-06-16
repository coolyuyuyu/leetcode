class Solution {
public:
    int maxDiff(int num) {
        vector<int> digits;
        for (; num; num /= 10) {
            digits.push_back(num % 10);
        }
        std::reverse(digits.begin(), digits.end());

        int maxNum = 0; {
            auto itr = std::find_if(digits.begin(), digits.end(), [](int d){ return d != 9; });
            int x = itr != digits.end() ? *itr : 9;
            int y = 9;
            for (int d : digits) {
                maxNum *= 10;
                maxNum += (d == x ? y : d);
            }
        }

        int minNum = 0; {
            int x, y;
            if (digits[0] == 1) {
                auto itr = std::find_if(digits.begin(), digits.end(), [](int d){ return d > 1; });
                if (itr != digits.end()) {
                    x = *itr;
                    y = 0;
                }
                else {
                    x = 1;
                    y = 1;
                }
            }
            else {
                x = digits[0];
                y = 1;
            }
            for (int d : digits) {
                minNum *= 10;
                minNum += (d == x ? y : d);
            }
        }

        return maxNum - minNum;
    }
};
