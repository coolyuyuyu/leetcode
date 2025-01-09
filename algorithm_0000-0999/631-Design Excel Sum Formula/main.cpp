class Excel {
public:
    Excel(int height, char width)
        : m_vals(height + 1, vector<int>(width - 'A' + 1 + 1))
        , m_exprs(height + 1, vector<vector<string>>(width - 'A' + 1 + 1)) {
    }

    void set(int row, char col, int val) {
        m_vals[row][col - 'A' + 1] = val;
        m_exprs[row][col - 'A' + 1].clear();
    }

    int get(int row, char col) {
        if (m_exprs[row][col - 'A' + 1].empty()) {
            return m_vals[row][col - 'A' + 1];
        }

        int ret = 0;
        for (const string& expr : m_exprs[row][col - 'A' + 1]) {
            size_t sep = expr.find(':');
            if (sep == string::npos) {
                auto [r, c] = parse(expr);
                ret += get(r, c);
            }
            else {
                auto [top, lft] = parse(expr.substr(0, sep));
                auto [btm, rht] = parse(expr.substr(sep + 1));
                for (auto r = top; r <= btm; ++r) {
                    for (auto c = lft; c <= rht; ++c) {
                        ret += get(r, c);
                    }
                }
            }
        }

        return ret;
    }

    int sum(int row, char col, vector<string> numbers) {
        m_exprs[row][col - 'A' + 1] = numbers;
        return get(row, col);
    }

private:
    pair<int, char> parse(const string& s) {
        return {std::stoi(s.substr(1)), s[0]};
    }

    vector<vector<int>> m_vals;
    vector<vector<vector<string>>> m_exprs;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
