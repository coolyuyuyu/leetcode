class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        size_t indexA = 0, indexB = 0;
        size_t countA = 1, countB = 1;
        char charA, charB;
        while (countA && countB) {
            countA = 0;
            for (size_t index = indexA; index < name.size(); ++index) {
                if (index + 1 == name.size() || name[index] != name[index + 1]) {
                    countA = index - indexA + 1;
                    charA = name[index];

                    indexA = index + 1;
                    break;
                }
            }

            countB = 0;
            for (size_t index = indexB; index < typed.size(); ++index) {
                if (index + 1 == typed.size() || typed[index] != typed[index + 1]) {
                    countB = index - indexB + 1;
                    charB = typed[index];

                    indexB = index + 1;
                    break;
                }
            }

            if (countA > 0 && countB > 0) {
                if (charA != charB) {
                    return false;
                }
                
                if (countA > countB) {
                    return false;
                }
            }
        }

        if (countA && !countB) {
            return false;
        }
        else if (!countA && countB) {
            return false;
        }
        else {
            return true;
        }
    }
};