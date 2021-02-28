class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool lastOne = true;
        for (size_t i = 0; i < bits.size();) {
            if (bits[i] == 0) {
                lastOne = true;
                i += 1;
            }
            else {
                lastOne = false;
                i += 2;
            }
        }

        return lastOne;
    }
};