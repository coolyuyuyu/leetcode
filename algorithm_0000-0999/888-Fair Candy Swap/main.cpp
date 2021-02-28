class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int totalLengthA = 0;
        for (int length : A) {
            totalLengthA += length;
        }

        unordered_set<int> lengthsB;
        int totalLengthB = 0;
        for (int length : B) {
            lengthsB.emplace(length);
            totalLengthB += length;
        }

        int delta = (totalLengthA - totalLengthB) / 2;
        for (int lengthA : A) {
            if (lengthsB.find(lengthA - delta) != lengthsB.end()) {
                return { lengthA, lengthA - delta };
            }
        }

        assert(false);
    }
};