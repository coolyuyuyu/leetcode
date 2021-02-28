class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string t = "";
        for (int i = 0; i < s.size(); i += (2 * numRows - 2)) {
            t.push_back(s.at(i));
        }

        for (int i = 1; (i + 1) < numRows; ++i) {
            int x = i;
            int y = i + (2 * numRows - 2) - i * 2;
            while (true) {
                if (s.size() <= x) {
                    break;
                }
                t.push_back(s.at(x));
                x += (2 * numRows - 2);

                if (s.size() <= y) {
                    break;
                }
                t.push_back(s.at(y));
                y += (2 * numRows - 2);
            }
        }

        for (int i = numRows - 1; i < s.size(); i += (2 * numRows - 2)) {
            t.push_back(s.at(i));
        }

        return t;
    }
};