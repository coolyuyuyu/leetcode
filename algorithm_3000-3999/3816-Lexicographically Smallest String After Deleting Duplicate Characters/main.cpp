class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> remaining(26, 0);
        for (char c : s) {
            ++remaining[c - 'a'];
        }
        vector<int> used(26, 0);

        string ret;
        for (char c : s) {
            --remaining[c - 'a'];
            while (!ret.empty() && ret.back() > c && (used[ret.back() - 'a'] > 1 || remaining[ret.back() - 'a'] > 0)) {
                --used[ret.back() - 'a'];
                ret.pop_back();
            }
            ++used[c - 'a'];
            ret.push_back(c);
        }
        while (!ret.empty() && used[ret.back() - 'a'] > 1) {
            --used[ret.back() - 'a'];
            ret.pop_back();
        }

        return ret;
    }
};
