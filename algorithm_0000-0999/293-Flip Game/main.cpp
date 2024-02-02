class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ret;
        for (int i = 1; i < currentState.size(); ++i) {
            if (currentState[i - 1] == '-' || currentState[i] == '-') {
                continue;
            }
            ret.push_back(currentState);
            std::fill_n(ret.back().begin() + i - 1, 2, '-');
        }

        return ret;
    }
};
