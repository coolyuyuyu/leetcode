class Solution {
public:
    string removeDigit(string number, char digit) {
        for (int i = 0; i + 1 < number.size(); ++i) {
            if (number[i] == digit && digit < number[i + 1]) {
                return number.substr(0, i) + number.substr(i + 1);
            }
        }

        size_t pos = number.find_last_of(digit);
        return number.substr(0, pos) + number.substr(pos + 1);;
    }
};
