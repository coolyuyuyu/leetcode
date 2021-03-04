class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operators = {
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"*", multiplies<int>()},
            {"/", divides<int>()},
        };

        stack<int> stk;
        for (const string& token : tokens) {
            auto itr = operators.find(token);
            if (itr != operators.end()) {
                int v2 = stk.top();
                stk.pop();
                int v1 = stk.top();
                stk.pop();

                stk.push(itr->second(v1, v2));
            }
            else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};