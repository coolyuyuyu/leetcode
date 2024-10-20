class Solution {
public:
    bool eval(char opr, const vector<bool>& opds) {
        switch (opr) {
        case '!':
            assert(opds.size() == 1);
            return !opds[0];
        case '&':
            return std::find(opds.begin(), opds.end(), false) == opds.end();
        case '|':
            return std::find(opds.begin(), opds.end(), true) != opds.end();
        default:
            assert(false);
            return false;
        }
    }

    bool byStk(const string& expression) {
        stack<pair<char, vector<bool>>> stk;
        stk.emplace('~', vector<bool>{});
        for (int i = 0, n = expression.size(); i < n; ++i) {
            switch (expression[i]) {
            case '!':
            case '&':
            case '|':
                stk.emplace(expression[i], vector<bool>{});
                ++i; // skip '('
                break;
            case 't':
                stk.top().second.push_back(true);
                break;
            case 'f':
                stk.top().second.push_back(false);
                break;
            case ')': {
                auto [opr, opds] = stk.top();
                stk.pop();
                stk.top().second.push_back(eval(opr, opds));
            }
            case ',':
                break;
            default:
                assert(false);
                break;
            }
        }

        return stk.top().second[0];
    };

    bool byDfs(const string& expression) {
        std::function<bool(int, int)> dfs = [&](int bgn, int end) {
            char opr = expression[bgn];
            vector<bool> opds;
            for (int i = bgn + 2; i < end - 1; ++i) {
                switch (expression[i]) {
                case '!':
                case '&':
                case '|': {
                    int j = i + 1;
                    int cnt = 0;
                    for (; j < end - 1; ++j) {
                        if (expression[j] == '(') {
                            ++cnt;
                        }
                        else if (expression[j] == ')') {
                            if (--cnt == 0) {
                                opds.push_back(dfs(i, j + 1));
                                break;
                            }
                        }
                    }
                    i = j;
                    break;
                }
                case 't':
                    opds.push_back(true);
                    break;
                case 'f':
                    opds.push_back(false);
                    break;
                case ')': {
                    break;;
                }
                case ',':
                    break;
                default:
                    assert(false);
                    break;
                }
            }
            return eval(opr, opds);
        };
        return dfs(0, expression.size());
    };

    bool parseBoolExpr(string expression) {
        //return byStk(expression);
        return byDfs(expression);
    }
};
