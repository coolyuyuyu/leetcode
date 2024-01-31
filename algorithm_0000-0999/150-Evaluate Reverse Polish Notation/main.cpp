class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, std::function<int(int, int)>> operators = {
            {"+", std::plus<int>()},
            {"-", std::minus<int>()},
            {"*", std::multiplies<int>()},
            {"/", std::divides<int>()},
        };

        stack<int> stk;
        for (const string& token : tokens) {
            auto itr = operators.find(token);
            if (itr != operators.end()) {
                int y = stk.top(); stk.pop();
                int x = stk.top(); stk.pop();
                stk.push(itr->second(x, y));
            }
            else {
                stk.push(std::stoi(token));
            }
        }

        return stk.top();
    }
};
