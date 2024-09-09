class Solution {
public:
    string convertDateToBinary(string date) {
        std::function<string(int)> toBinStr = [](int num) {
            string ret;
            for (; num; num >>= 1) {
                ret += num & 1 ? '1' : '0';
            }
            std::reverse(ret.begin(), ret.end());
            return ret;
        };

        return toBinStr(std::stoi(date.substr(0, 4))) + "-" + toBinStr(std::stoi(date.substr(5, 2))) + "-" + toBinStr(std::stoi(date.substr(8, 2)));
    }
};
