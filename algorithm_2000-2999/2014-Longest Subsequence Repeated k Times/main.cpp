class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        // t: longestSubsequenceRepeatedK of s
        // len(t) * k <= n < 8 * k
        // => len(t) <= 7
        // => the number of different letters whose frequency >= k is less then 8 (<=7)

        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        vector<char> letters;
        for (const auto& [c, cnt] : cnts) {
            if (cnt >= k) {
                letters.push_back(c);
            }
        }

        std::function<bool(const string&)> checkKRepeated = [&](const string& t) {
            if (t.empty()) { return true; }

            for (int i = 0, j = 0, repeatCnt = 0; i < s.size(); ++i) {
                if (s[i] != t[j]) { continue; }
                if (++j >= t.size()) {
                    j = 0;
                    if (++repeatCnt >= k) {
                        return true;
                    }
                }
            }
            return false;
        };

        string ret;
        std::function<void(const vector<char>&, string&)> dfs = [&](const vector<char>&, string& seq) {
            if (!checkKRepeated(seq)) {
                return;
            }

            if (seq.size() > ret.size() || (seq.size() == ret.size() && seq > ret)) {
                ret = seq;
            }

            for (char c : letters) {
                seq.push_back(c);
                dfs(letters, seq);
                seq.pop_back();
            }
        };
        string seq;
        dfs(letters, seq);

        return ret;
    }
};
