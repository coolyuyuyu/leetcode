class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> char2cnt;
        for (char c : s) {
            ++char2cnt[c];
        }

        unordered_map<int, string> freq2chars;
        for (const auto& [c, cnt] : char2cnt) {
            freq2chars[cnt] += c;
        }

        int curFreq = 0;
        string ret;
        for (const auto& [freq, chars] : freq2chars) {
            if (chars.size() > ret.size()) {
                ret = chars;
                curFreq = freq;
            }
            else if (chars.size() == ret.size() && freq > curFreq) {
                ret = chars;
                curFreq = freq;
            }
        }

        return ret;
    }
};
