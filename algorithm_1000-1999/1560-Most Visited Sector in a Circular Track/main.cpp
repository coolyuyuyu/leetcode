class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int src = rounds.front(), dst = rounds.back();

        vector<int> ret;
        if (src <= dst) {
            for (int i = src; i <= dst; ++i) {
                ret.push_back(i);
            }
        }
        else {
            for (int i = 1; i <= dst; ++i) {
                ret.push_back(i);
            }
            for (int i = src; i <= n; ++i) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
