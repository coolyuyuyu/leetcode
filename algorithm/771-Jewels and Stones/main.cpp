class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool mapping[255] = {false};
        for (size_t i = 0; i < J.size(); ++i) {
            mapping[J[i]] = true;
        }

        int count = 0;
        for (size_t i = 0; i < S.size(); ++i) {
            if (mapping[S[i]]) {
                ++count;
            }
        }

        return count;
    }
};