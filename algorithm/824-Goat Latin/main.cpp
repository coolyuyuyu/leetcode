class Solution {
public:
    inline bool checkVowel(char c) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
        }
    }

    string toGoatLatin(string S) {
        string sentence;

        size_t index = 1;
        istringstream iss(S);
        for (string word; iss >> word; ++index) {
            if (!checkVowel(word.front())) {
                word.push_back(word.front());
                word.erase(0, 1);
            }
            word.append("ma");

            for (size_t i = 1; i <= index; ++i) {
                word.push_back('a');
            }

            if (!sentence.empty()) {
                sentence.push_back(' ');
            }
            sentence.append(word);
        }

        return sentence;
    }
};