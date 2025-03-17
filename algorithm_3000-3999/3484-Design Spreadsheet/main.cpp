class Spreadsheet {
public:
    Spreadsheet(int rows)
        : m_vals(rows) {
        for (auto& row : m_vals) {
            row.fill(0);
        }
    }

    void setCell(string cell, int value) {
        auto [r, c] = decode(cell);
        m_vals[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = decode(cell);
        m_vals[r][c] = 0;
    }

    int getValue(string formula) {
        if (formula[0] == '=') {
            size_t sep = formula.find('+');
            string part1 = formula.substr(1, sep - 1);
            string part2 = formula.substr(sep + 1);
            return getValue(part1) + getValue(part2);
        }
        else if ('A' <= formula[0] && formula[0] <= 'Z') {
            const string& cell = formula;
            auto [r, c] = decode(cell);
            return m_vals[r][c];
        }
        else {
            return std::stoi(formula);
        }
    }

private:
    pair<int, int> decode(const string& cell) {
        return {std::stoi(cell.substr(1)) - 1, cell[0] - 'A'};
    }

    vector<array<int, 26>> m_vals;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
