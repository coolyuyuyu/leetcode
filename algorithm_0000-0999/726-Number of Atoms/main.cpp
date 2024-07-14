class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> cur;
        for (int i = 0; i < formula.size();) {
            if (formula[i] == '(') {
                stk.push(cur);
                cur.clear();
                ++i;
            }
            else if (formula[i] == ')') {
                ++i;

                int cnt = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    cnt = cnt * 10 + (formula[i++] - '0');
                }
                if (cnt == 0) {
                    cnt = 1;
                }

                for (const auto& [atom, _] : cur) {
                    cur[atom] *= cnt;
                }
                for (const auto& [atom, num] : stk.top()) {
                    cur[atom] += num;
                }
                stk.pop();
            }
            else {
                assert(isupper(formula[i]));
                string atom;
                atom += formula[i++];
                while (i < formula.size() && islower(formula[i])) {
                    atom += formula[i++];
                }

                int cnt = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    cnt = cnt * 10 + (formula[i++] - '0');
                }
                if (cnt == 0) {
                    cnt = 1;
                }

                cur[atom] += cnt;
            }
        }

        string ret;
        for (const auto& [atom, cnt] : cur) {
            ret += atom;
            if (cnt > 1) {
                ret += std::to_string(cnt);
            }
        }

        return ret;
    }
};
