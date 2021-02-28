class Solution {
private:
    string reduceBackspace(const string& s) {
        string result;
        result.reserve(s.size());

        for (char c : s) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else {
                result.push_back(c);
            }
        }

        return result;
    }

    class ReverseIterator {
    public:
        ReverseIterator(const string& str)
            : m_str(str)
            , m_itr(m_str.crbegin()) {
        }

        const char* next() {
            for (size_t i = 1; m_itr != m_str.crend(); ++m_itr) {
                i += (*m_itr == '#' ? 1 : -1);
                if (i == 0) {
                    break;
                }
            }

            if (m_itr == m_str.crend()) {
                return nullptr;
            }
            else {
                return &(*(m_itr++));
            }
        }

    private:
        const string& m_str;
        string::const_reverse_iterator m_itr;
    };

public:
    bool backspaceCompare_Reduce(const string& S, const string& T) {
        return reduceBackspace(S) == reduceBackspace(T);
    }

    bool backspaceCompare_ScanBackward(string S, string T) {
        ReverseIterator itr1(S), itr2(T);
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

    bool backspaceCompare(string S, string T) {
        //return backspaceCompare_Reduce(S, T);
        return backspaceCompare_ScanBackward(S, T);
    }
};