class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            vector<char> chars;
            vector<int> counts;

            char c = s[0];
            int count = 1;
            for (string::const_iterator iter = s.begin() + 1; iter != s.end(); ++iter) {
                if (*iter == c) {
                    ++count;
                }
                else {
                    chars.push_back(c);
                    counts.push_back(count);

                    c = *iter;
                    count = 1;
                }
            }
            chars.push_back(c);
            counts.push_back(count);
            assert(chars.size() == counts.size());

            string target;
            target.reserve(accumulate(counts.begin(), counts.end(), (size_t)0));            
            for (size_t i = 0; i < chars.size(); ++i) {
                target.push_back(counts[i] + '0');
                target.push_back(chars[i]);
            }
            s = target;
        }
        return s;
    }
};