class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();

        unordered_set<string> nums;
        for (int lft = 0; lft < n; ++lft) {
            if (!isdigit(word[lft])) {
                continue;
            }

            int rht = lft;
            while (rht < n && isdigit(word[rht])) {
                ++rht;
            }
            while (word[lft] == '0') {
                ++lft;
            }
            nums.insert(word.substr(lft, rht - lft));

            lft = rht - 1;
        }

        return nums.size();
    }
};
