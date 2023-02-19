class Solution {
public:
    // two pointer
    // Time: O(n)
    int f1 (const string& s) {
        // [lft, rht)
        vector<bool> duplicate(128, false);
        int ret = 0;
        for (int lft = 0, rht = 0; rht < s.size();) {
            if (duplicate[s[rht]] == false) {
                duplicate[s[rht++]] = true;
            }
            else if (duplicate[s[lft]] == true) {
                duplicate[s[lft++]] = false;
            }

            ret = std::max(ret, rht - lft);
        }

        return ret;
    }

    // two pointer, lft jumps
    // Time: O(n)
    int f2 (const string& s) {
        // [lft, rht]
        vector<int> lastIndexes(128, -1);
        int ret = 0;
        for (int lft = 0, rht = 0; rht < s.size(); ++rht) {
            if (0 <= lastIndexes[s[rht]]) {
                lft = std::max(lft, lastIndexes[s[rht]] + 1);
            }
            lastIndexes[s[rht]] = rht;
 
            ret = std::max(ret, rht - lft + 1);
        }

        return ret;
    }

    int lengthOfLongestSubstring(string s) {
        //return f1(s);
        return f2(s);
    }
};
