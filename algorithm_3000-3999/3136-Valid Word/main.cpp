class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        bool conatinV = false, containC = false;
        for (char c : word) {
            if (!isalnum(c)) { return false; }
            if (isdigit(c)) { continue; }

            switch(tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                conatinV = true;
                break;
            default:
                containC = true;
                break;
            }
        }

        return conatinV && containC;
    }
};
