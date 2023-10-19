class Solution {
public:
    bool reduceAndCompare(const string& s, const string& t) {
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

    bool compareOnTheFly(const string& s, const string& t) {
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

        BackspaceStringReverseIterator itr1(s), itr2(t);
        while (true) {
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
        //return reduceAndCompare(s, t);
        return compareOnTheFly(s, t);
    }
};