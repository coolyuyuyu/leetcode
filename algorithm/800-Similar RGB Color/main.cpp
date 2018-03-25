class Solution {
public:
    string similarRGB(string color) {
        static vector<char> chars = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

        string result = "#";
        for (int i = 0; i < 3; ++i) {
            int num;
            sscanf(color.c_str() + i * 2 + 1, "%2x", &num);

            int quotient = num / 17;
            int remainder = num % 17;
            if (remainder <= 8) {
                result.push_back(chars[quotient]);
                result.push_back(chars[quotient]);
            }
            else {
                result.push_back(chars[quotient + 1]);
                result.push_back(chars[quotient + 1]);
            }
        }

        return result;
    }
};