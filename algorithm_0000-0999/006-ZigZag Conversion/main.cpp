class Solution {
public:
    // Time: O(n), Space(n)
    string f1(const string&s, int numRows) {
        vector<string> lines(numRows);

        for (int i = 0; i < s.size();) {
            for (int r = 0; r < numRows && i < s.size(); ++r) {
                lines[r].push_back(s[i++]);
            }

            for (int r = numRows - 1; 1 < r-- && i < s.size();) {
                lines[r].push_back(s[i++]);
            }
        }

        string ret;
        for (const string& line : lines) {
            ret += line;
        }

        return ret;
    }

    // Time: O(n), Space(1)
    string f2(const string&s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string ret;

        int numOfCharsInSection = 2 * (numRows - 1);
        for (int i = 0; i < s.size(); i += numOfCharsInSection) {
            ret += s[i];
        }
        for (int r = 1; r < (numRows - 1); ++r) {
            int dist = numOfCharsInSection - 2 * r;
            for (int i = r; i < s.size(); i += numOfCharsInSection) {
                ret += s[i];
                if ((i + dist) < s.size()) {
                    ret += s[i + dist];
                }
            }
        }
        for (int i = numRows - 1; i < s.size(); i += numOfCharsInSection) {
            ret += s[i];
        }

        return ret;
    }

    string convert(string s, int numRows) {
        //return f1(s, numRows);
        return f2(s, numRows);
    }
};
