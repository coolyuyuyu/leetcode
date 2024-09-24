class Solution {
public:
    int eval(string s) {
        s = "+" + s;

        vector<int> nums;
        for (int i = 0; i < s.size(); ++i) {
            char op = s[i];
            int j = i + 1;
            if (s[j] == '-') {
                ++j;
            }
            while (std::isdigit(s[j])) {
                ++j;
            }
            int num = std::stoi(s.substr(i + 1, j - i - 1));
            switch (op) {
            case '+': nums.push_back(num); break;
            case '-': nums.push_back(-num); break;
            case '*': nums.back() *= num; break;
            case '/': nums.back() /= num; break;
            default: assert(false); break;
            }
            i = j - 1;
        }

        return std::accumulate(nums.begin(), nums.end(), 0);
    }

    int calculate(string s) {
        stack<string> stk;
        string cur;
        for (char c : s) {
            if (c == '(') {
                stk.push(cur);
                cur.clear();
            }
            else if (c == ')') {
                cur = stk.top() + std::to_string(eval(cur));
                stk.pop();
            }
            else if (c == ' ') {
            }
            else {
                cur += c;
            }
        }

        return eval(cur);
    }
};
