class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        for (int i = 1; i < n; ++i) {
            ret.push_back(i);
        }
        ret.push_back(- (n * (n - 1) / 2));

        return ret;
    }
};
