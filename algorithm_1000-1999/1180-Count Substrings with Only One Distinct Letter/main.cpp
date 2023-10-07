class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnts;
        for (char c : text) {
            ++cnts[c];
        }

        cnts['l'] /= 2;
        cnts['o'] /= 2;

        return std::min({cnts['b'], cnts['a'], cnts['l'], cnts['o'], cnts['n']});
    }
};
