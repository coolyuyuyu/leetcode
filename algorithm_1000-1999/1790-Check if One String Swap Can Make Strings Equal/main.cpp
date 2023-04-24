class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        vector<int> indexes;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                indexes.push_back(i);
                if (2 < indexes.size()) {
                    return false;
                }
            }
        }

        if (indexes.empty()) {
            return true;
        }
        else if (indexes.size() == 1) {
            return false;
        }
        else {
            return s1[indexes[0]] == s2[indexes[1]] && s1[indexes[1]] == s2[indexes[0]];
        }
    }
};
