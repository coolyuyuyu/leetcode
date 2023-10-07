class Solution {
public:
    string toHexspeak(string num) {
        std::stringstream sstream;
        sstream << std::hex << std::uppercase << std::stol(num, nullptr);
        std::string hexstr = sstream.str();
        for (char& c : hexstr) {
            if (c == '0') {
                c = 'O';
            }
            else if (c == '1') {
                c = 'I';
            }
            else if ('2' <= c && c <= '9') {
                return "ERROR";
            }
        }

        return hexstr;
    }
};
