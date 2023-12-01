class Solution {
public:
    vector<int> math1(int n) {
        vector<int> ret = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = ret.size(); 0 < j--;) {
                ret.push_back(ret[j] | (1 << i));
            }
        }

        return ret;
    }

    vector<int> math2(int n) {
        vector<int> ret(1 << n);
        for (int i = 1; i < ret.size(); ++i) {
            ret[i] = i ^ (i >> 1);
        }

        return ret;
    }

    vector<int> grayCode(int n) {
        //return math1(n);
        return math2(n);
    }
};
