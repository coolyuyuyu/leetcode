class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<long long(long long, long long)>> operators = {
            {"+", std::plus<long long>()},
            {"-", std::minus<long long>()},
            {"*", std::multiplies<long long>()},
            {"/", std::divides<long long>()},
        };

        stack<long long> stk;
        for (const auto& token : tokens) {
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
