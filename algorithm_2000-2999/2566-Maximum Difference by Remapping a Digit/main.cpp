class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> digits;
        for (; num; num /= 10) {
            digits.push_back(num % 10);
        }
        std::reverse(digits.begin(), digits.end());

        int maxVal = 0; {
            int targetD = digits[0];
            for (int i = 0; i < digits.size(); ++i) {
                if (digits[i] < 9) {
                    targetD = digits[i];
                    break;

                }
            }

            for (int i = 0; i < digits.size(); ++i) {
                maxVal *= 10;
                if (digits[i] == targetD) {
                    maxVal += 9;
                }
                else {
                    maxVal += digits[i];
                }
            }
        }

        int minVal = 0; {
            int targetD = digits[0];
            for (int i = 0; i < digits.size(); ++i) {
                minVal *= 10;
                if (digits[i] == targetD) {
                    minVal += 0;
                }
                else {
                    minVal += digits[i];
                }
            }
        }

        return maxVal - minVal;

    }
};
