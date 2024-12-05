class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        int i, j;
        for (i = 0, j = 0; i < n; ++i) {
            if (start[i] == 'X') { continue; }

            while (j < n && result[j] == 'X') {
                ++j;
            }
            if (j >= n || start[i] != result[j]) {
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
            if (result[j] != 'X') {
                return false;
            }
        }

        return true;
    }
};
