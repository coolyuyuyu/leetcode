class Solution {
public:
    bool isStrobogrammatic(string num) {
        static unordered_map<char, char> dict = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

        size_t lft = 0;
        size_t rht = num.size() - 1;
        while (lft < rht) {
            unordered_map<char, char>::const_iterator it = dict.find(num[lft]);
            if (it == dict.end() || it->second != num[rht]) {
                return false;
            }

            ++lft;
            --rht;
        }

        if (lft == rht) {
            return num[lft] == '0' || num[lft] == '1' || num[lft] == '8';
        }
        else {
            return true;
        }
    }
};