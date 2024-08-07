class Solution {
public:
    vector<string> lt20 = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> lt100 = {
        "", "Ten", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
    };

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        std::function<string(int)> f = [&](int num) -> string {
            if (num == 0) {
                return "";
            }
            else if (num < 20) {
                return " " + lt20[num];
            }
            else if (num < 100) {
                return " " + lt100[num / 10] + f(num % 10);
            }
            else if (num < 1'000) {
                return f(num / 100) + " Hundred" + f(num % 100);
            }
            else if (num < 1'000'000) {
                return f(num / 1'000) + " Thousand" + f(num % 1'000);
            }
            else if (num < 1'000'000'000) {
                return f(num / 1'000'000) + " Million" + f(num % 1'000'000);
            }
            else {
                return f(num / 1'000'000'000) + " Billion" + f(num % 1'000'000'000);
            }
        };

        return f(num).substr(1);
    }
};
