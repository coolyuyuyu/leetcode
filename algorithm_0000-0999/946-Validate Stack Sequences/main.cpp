class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        size_t indexPushed = 0, indexPopped = 0;
        while (indexPopped < popped.size()) {
            while (stk.empty() || stk.top() != popped[indexPopped]) {
                if (pushed.size() <= indexPushed ) {
                    return false;
                }
                stk.push(pushed[indexPushed++]);
            }

            stk.pop();
            ++indexPopped;
        }

        return true;
    }
};
