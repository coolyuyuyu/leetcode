class Solution {
public:
    // Time: O(n), Space: O(n)
    bool simulateAndCompare(string s, string t) {
        std::function<string(const string&)> f = [](const string& str) {
            string ret;
            for (char c : str) {
                if (c != '#') {
                    ret.push_back(c);
                }
                else if (!ret.empty()){
                    ret.pop_back();
                }
            }

            return ret;
        };

        return f(s) == f(t);
    }

    // Time: O(n), Space: O(1)
    bool dualptrFwdOnTheFly(string s, string t) {
        std::function<int(string&)> f = [](string& str) {
            int slow = 0;
            for (int fast = 0; fast < str.size(); ++fast) {
                if (str[fast] != '#') {
                    str[slow++] = str[fast];
                }
                else {
                    slow = std::max(0, slow - 1);
                }
            }

            return slow;
        };

        int i = f(s), j = f(t);
        return s.compare(0, i, t, 0, j) == 0;
    }

    // Time: O(n), Space: O(1)
    bool compareBwdOnTheFly(string s, string t) {
        class BackspaceStringReverseIterator {
        public:
            BackspaceStringReverseIterator(const string& str)
                : m_str(str)
                , m_idx(m_str.size()) {
            }

            const char* next() {
                for (int skip = 1; 0 < m_idx; --m_idx) {
                    skip += (m_str[m_idx - 1] == '#' ? 1 : -1);
                    if (skip == 0) {
                        break;
                    }
                }

                if (0 < m_idx) {
                    return &(m_str[--m_idx]);
                }
                else {
                    return nullptr;
                }
            }

        private:
            const string& m_str;
            size_t m_idx;
        };

        for (BackspaceStringReverseIterator itr1(s), itr2(t); true;) {
            const char* pChar1 = itr1.next();
            const char* pChar2 = itr2.next();
            if (pChar1 && pChar2) {
                if (*pChar1 != *pChar2) {
                    return false;
                }
            }
            else if (!pChar1 && !pChar2) {
                break;
            }
            else {
                return false;
            }
        }

        return true;
    }

    bool backspaceCompare(string s, string t) {
        //return simulateAndCompare(s, t);
        //return dualptrFwdOnTheFly(s, t);
        return compareBwdOnTheFly(s, t);
    }
};
