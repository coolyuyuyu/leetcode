class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        bitset<101> bits;
        for (int i : bulbs) {
            bits.flip(i);
        }

        vector<int> ret;
        for (int i = 0; i < bits.size(); ++i) {
            if (bits.test(i)) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
