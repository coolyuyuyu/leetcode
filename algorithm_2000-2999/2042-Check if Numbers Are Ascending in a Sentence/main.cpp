class Solution {
public:
    bool areNumbersAscending(string s) {
        int lastNum = 0;

        istringstream iss(s);
        for (string word; iss >> word;) {
            if (isdigit(word[0])) {
                int num = std::stoi(word);
                if (num <= lastNum) {
                    return false;
                }
                lastNum = num;
            }
        }

        return true;
    }
};
