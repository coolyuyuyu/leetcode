class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i, j;
        for (i = 0, j = 0; i < n; ++i) {
            if (start[i] == '_') { continue; }

            while (j < n && target[j] == '_') {
                ++j;
            }
            if (j >= n || start[i] != target[j]) {
                return false;
            }

            if (start[i] == 'L' && i < j) {
                return false;
            }
            if (start[i] == 'R' && i > j) {
                return false;
            }

            ++j;
        }

        for (; j < n; ++j) {
            if (target[j] != '_') {
                return false;
            }
        }

        return true;
    }
};
