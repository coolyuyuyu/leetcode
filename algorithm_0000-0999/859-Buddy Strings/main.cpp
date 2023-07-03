class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }

        size_t len = A.size();
        size_t i = 0;

        size_t index1 = string::npos; {
            for (; i < len; ++i) {
                if (A.at(i) != B.at(i)) {
                    index1 = i;
                    ++i;
                    break;
                }
            }
        }
        if (index1 == string::npos) {
            unordered_set<char> seen;
            for (char c : A) {
                auto p = seen.insert(c);
                if (p.second == false) {
                    return true;
                }
            }

            return false;
        }

        size_t index2 = string::npos; {
            for (; i < len; ++i) {
                if (A.at(i) != B.at(i)) {
                    index2 = i;
                    ++i;
                    break;
                }
            }
        }
        if (index2 == string::npos) {
            return false;
        }

        if (A[index1] != B[index2] || A[index2] != B[index1]) {
            return false;
        }

        size_t index3 = string::npos; {
            for (; i < len; ++i) {
                if (A.at(i) != B.at(i)) {
                    index3 = i;
                    ++i;
                    break;
                }
            }
        }
        if (index3 != string::npos) {
            return false;
        }

        return true;
    }
};
