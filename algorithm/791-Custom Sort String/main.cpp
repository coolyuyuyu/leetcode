class Solution {
public:
    struct CustomLess{
    public:
        CustomLess(const string& s)
            : m_vals(26, 0) {
            for (size_t i = 0; i < s.size(); ++i) {
                m_vals[s[i] - 'a'] = i + 1;
            }
        }

        bool operator() (const char x, const char y) const{
            return m_vals[x - 'a'] < m_vals[y - 'a'];
        }
    private:
        vector<int> m_vals;
    };

    string customSortString(string S, string T) {
        sort(T.begin(), T.end(), CustomLess(S));
        return T;
    }
};