class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0;
        for (int lft : left) {
            ret = std::max(ret, lft);
        }
        for (int rht : right) {
            ret = std::max(ret, n - rht);
        }

        return ret;
    }
};
