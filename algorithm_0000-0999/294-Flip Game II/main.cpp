class Solution {
public:
    bool canWin(string currentState) {
        for (int i = 1; i < currentState.size(); ++i) {
            if (currentState[i - 1] == '+' && currentState[i] == '+') {
                currentState[i - 1] = currentState[i] = '-';
                if (!canWin(currentState)) {
                    return true;
                }
                currentState[i - 1] = currentState[i] = '+';
            }
        }

        return false;
    }
};
