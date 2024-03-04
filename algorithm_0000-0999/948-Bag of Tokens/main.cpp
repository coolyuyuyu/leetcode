class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        std::sort(tokens.begin(), tokens.end());
        int score = 0;
        int ret = 0;
        for (int lft = 0, rht = n - 1; lft <= rht;) {
            if (power >= tokens[lft]) {
                power -= tokens[lft];
                score += 1;
                lft++;
                ret = std::max(ret, score);
            }
            else if (score > 0) {
                power += tokens[rht];
                score -= 1;
                --rht;
            }
            else {
                break;
            }
        }

        return ret;
    }
};
