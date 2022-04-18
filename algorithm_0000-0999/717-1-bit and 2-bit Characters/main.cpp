class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        assert(!bits.empty());

        bool isLastOneBit = true;
        for (size_t i = 0; i < bits.size();) {
            if (bits[i] == 1) {
                isLastOneBit = false;
                i += 2;
            }
            else {
                isLastOneBit = true;
                i += 1;
            }
        }

        return isLastOneBit;
    }
};
