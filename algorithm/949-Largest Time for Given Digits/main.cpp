class Solution {
public:
    int largestMinutesFromDigits(vector<int>& digits, size_t index) {
        if (4 <= index) {
            if (digits[0] == 2) {
                if (3 < digits[1]) {
                    return -1;
                }
            }
            else if (2 < digits[0]) {
                return -1;
            }

            if (5 < digits[2]) {
                return -1;
            }

            return digits[0] * 600 + digits[1] * 60 + digits[2] * 10 + digits[3];
        }

        int largestMinutes = -1;
        for (size_t i = index; i < 4; ++i) {
            swap(digits[index], digits[i]);
            int minutes = largestMinutesFromDigits(digits, index + 1);
            largestMinutes = max(largestMinutes, minutes);
            swap(digits[index], digits[i]);
        }

        return largestMinutes;
    }

    string largestTimeFromDigits(vector<int>& A) {
        int ans = largestMinutesFromDigits(A, 0);
        if (ans < 0) {
            return "";
        }

        ostringstream oss;
        int hour = ans / 60;
        if (hour < 10) {
            oss << 0;
        }
        oss << hour;

        oss << ":";

        int minute = ans % 60;
        if (minute < 10) {
            oss << 0;
        }
        oss << minute;

        return oss.str();
    }
};