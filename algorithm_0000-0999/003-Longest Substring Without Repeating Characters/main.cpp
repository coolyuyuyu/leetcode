class Solution {
public:
    // Time: O(n^2)
    int quadratic(const string& s) {
        size_t ans = 0;
        for (size_t i = 0; i < s.size() && ans < (s.size() - i); ++i) {
            set<char> chars;
            for (size_t j = i; j < s.size(); ++j) {
                if (chars.insert(s[j]).second == false) {
                    break;
                }
            }
            ans = std::max(ans, chars.size());
        }

        return ans;
    }

    // Time: O(n)
    int linear(const string& s) {
        vector<int> lastIndexes(128, -1);
        int ans = 0;
        for (int lft = 0, rht = 0; rht < s.size(); ++rht) {
            lft = std::max(lft, lastIndexes[s[rht]] + 1);
            lastIndexes[s[rht]] = rht;
            ans = std::max(ans, rht - lft + 1);
        }

        return ans;
    }

    int lengthOfLongestSubstring(string s) {
        //return quadratic(s);
        return linear(s);
    }
};
