class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        auto checkLeapYear = [](int year) {
            return ((year % 400) == 0) || ((year % 4) == 0 && (year % 100) != 0);
        };

        int days = 0;

        for (int y = 1971; y < year; ++y) {
            days += (checkLeapYear(y) ? 366 : 365);
        }

        static vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int m = 1; m < month; ++m) {
            days += daysInMonth[m];
        }
        if (2 < month && checkLeapYear(year)) {
            ++days;
        }

        days += day;

        // 1971/01/01: Friday
        static vector<string> dayNames = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", };
        return dayNames[(days - 1 ) % 7];
    }
};
