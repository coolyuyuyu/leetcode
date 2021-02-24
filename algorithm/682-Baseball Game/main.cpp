class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for (const string& op : ops) {
            if (op == "+") {
                int tmp1 = stk.top();
                stk.pop();
                int tmp2 = stk.top() + tmp1;

                stk.push(tmp1);
                stk.push(tmp2);
            }
            else if (op == "D") {
                stk.push(stk.top() * 2);
            }
            else if (op == "C") {
                stk.pop();
            }
            else {
                stk.push(stoi(op));
            }
        }

        int sum = 0;
        for (; !stk.empty(); stk.pop()) {
            sum += stk.top();
        }
        return sum;
    }
};