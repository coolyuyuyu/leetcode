class Solution {
public:
    // Time: O(NlogN), Space: O(1)
    bool compareSorted(string& s, string& t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }

    // Time: O(N), Space: O(1)
    bool compareFreq1(const string& s, const string& t) {
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++freq1[s[i] - 'a'];
            ++freq2[t[i] - 'a'];
        }

        return freq1 == freq2;
    }

    // Time: O(N), Space: O(1)
    bool compareFreq2(const string& s, const string& t) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        return std::all_of(freq.begin(), freq.end(), [](int f) { return f == 0; });
    }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        //return compareSorted(s, t);
        //return compareFreq1(s, t);
        return compareFreq2(s, t);
    }
};
