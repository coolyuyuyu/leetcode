class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ret = true;
        for (int i = 0; i < bits.size();) {
            if (bits[i] == 0) {
                i += 1;
                ret = true;
            }
            else {
                i += 2;
                ret = false;
            }
        }

        return ret;
    }
};
