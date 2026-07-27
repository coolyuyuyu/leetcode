class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnts(26, 0);
        for (char c : text) {
            ++cnts[c - 'a'];
        }
        cnts['l' - 'a'] /= 2;
        cnts['o' - 'a'] /= 2;

        return std::min({cnts['b' - 'a'], cnts['a' - 'a'], cnts['l' - 'a'], cnts['o' - 'a'], cnts['n' - 'a']});
    }
};
