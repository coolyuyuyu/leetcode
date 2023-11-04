class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int n = s.size();

        vector<int> indexes;
        for (int i = 0; i < n; ++i) {
            if (s[i] != goal[i]) {
                indexes.push_back(i);
                if (indexes.size() >= 3) {
                    return false;
                }
            }
        }
        if (indexes.size() == 1) {
            return false;
        }

        if (indexes.size() == 0) {
            vector<bool> dup(26, 0);
            for (int i = 0; i < n; ++i) {
                if (dup[s[i] - 'a']) {
                    return true;
                }
                dup[s[i] - 'a'] =  true;
            }
        }
        else {
            if (s[indexes[0]] == goal[indexes[1]] && s[indexes[1]] == goal[indexes[0]]) {
                return true;
            }
        }

        return false;
    }
};
