class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret = {0, 1};
        for (int i = 1; i < n; ++i) {
            for (int j = ret.size(); 0 < j--;) {
                ret.push_back(ret[j] | (1 << i));
            }
        }
        return ret;
    }
};
