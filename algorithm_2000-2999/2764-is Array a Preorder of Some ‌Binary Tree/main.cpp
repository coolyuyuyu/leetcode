class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) {
        stack<int> stk({nodes[0][0]});
        for (int i = 1; i < nodes.size(); ++i) {
            auto node = nodes[i];
            while (!stk.empty() && stk.top() != node[1]) {
                auto node = stk.top();
                stk.pop();
            }
            if (stk.empty()) {
                return false;
            }

            stk.push(node[0]);
        }

        return true;
    }
};
