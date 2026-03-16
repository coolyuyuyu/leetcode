class Excel {
private:
    struct Node {
    public:
        void invalidate() {
            for (Node* nxt : nxts) {
                nxt->invalidate();
            }
            valid = false;
        }

        int getValue() {
            if (valid || pres.empty()) {
                return val;
            }

            val = 0;
            for (Node* pre : pres) {
                val += pre->getValue();
            }

            valid = true;

            return val;
        }

        vector<Node*> nxts;
        vector<Node*> pres;
        bool valid = false;
        int val = 0;
    };

    Node m_nodes[26][26];

public:
    Excel(int height, char width)
        : m_rowCnt(height)
        , m_colCnt(width - 'A') {
    }

    void set(int row, char column, int val) {
        auto [r, c] = getRowCol(row, column);
        m_nodes[r][c].invalidate();
        m_nodes[r][c].val = val;
        m_nodes[r][c].pres.clear();
    }

    int get(int row, char column) {
        auto [r, c] = getRowCol(row, column);
        return m_nodes[r][c].getValue();
    }

    int sum(int row, char column, vector<string> numbers) {
        auto [r, c] = getRowCol(row, column);
        Node* cur = &m_nodes[r][c];
        cur->invalidate();
        cur->pres.clear();

        for (const string& number : numbers) {
            size_t sep = number.find(':');
            if (sep == string::npos) {
                auto [r, c] = parse(number);
                Node* pre = &m_nodes[r][c];
                cur->pres.push_back(pre);
                pre->nxts.push_back(cur);
            }
            else {
                auto [top, lft] = parse(number.substr(0, sep));
                auto [btm, rht] = parse(number.substr(sep + 1));
                for (auto r = top; r <= btm; ++r) {
                    for (auto c = lft; c <= rht; ++c) {
                        Node* pre = &m_nodes[r][c];
                        cur->pres.push_back(pre);
                        pre->nxts.push_back(cur);
                    }
                }
            }
        }

        return cur->getValue();
    }

private:
    std::pair<int, int> getRowCol(int row, char column) {
        return {row - 1, column - 'A'};
    }

    pair<int, int> parse(string_view s) {
        int r;
        std::from_chars(s.data() + 1, s.data() + s.size(), r);
        r -= 1;
        int c = s[0] - 'A';
        return {r, c};
    }

    int m_rowCnt;
    int m_colCnt;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
