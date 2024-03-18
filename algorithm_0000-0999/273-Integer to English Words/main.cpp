class Solution {
public:
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> below100 = {
        "", "Ten", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
    };

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        std::function<string(int)> num2str = [&](int num) -> string {
            if (num == 0) {
                return "";
            }
            else if (num < 20) {
                return string(" ") + below20[num];
            }
            else if (num < 100) {
                return string(" ") + below100[num / 10]  + num2str(num % 10);
            }
            else if (num < 1'000) {
                return num2str(num / 100) + " " + "Hundred" + num2str(num % 100);
            }
            else if (num < 1'000'000) {
                return num2str(num / 1'000) + " " + "Thousand" + num2str(num % 1'000);
            }
            else if (num < 1'000'000'000) {
                return num2str(num / 1'000'000) + " " + "Million" +  num2str(num % 1'000'000);
            }
            else {
                return num2str(num / 1'000'000'000) + " " + "Billion" +  num2str(num % 1'000'000'000);
            }
        };

        return num2str(num).substr(1);
    }
};
