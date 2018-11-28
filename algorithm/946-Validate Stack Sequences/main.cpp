class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        auto itrPushed = pushed.begin();
        auto itrPopped = popped.begin();
        while (itrPopped != popped.end()) {
            int val = *itrPopped;
            while (stk.empty() || stk.top() != val) {
                if (itrPushed == pushed.end()) {
                    return false;
                }
                stk.push(*itrPushed);
                ++itrPushed;
            }

            stk.pop();
            ++itrPopped;
        }

        return true;
    }
};