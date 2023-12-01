class Solution {
public:
    vector<int> graycode1(int n, int start) {
        vector<int> ret = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = ret.size(); 0 < j--;) {
                ret.push_back(ret[j] | (1 << i));
            }
        }

        for (int i = 0; i < ret.size(); ++i) {
            if (ret[i] == start) {
                std::rotate(ret.begin(), ret.begin() + i, ret.end());
                break;
            }
        }

        return ret;
    }

    vector<int> graycode2(int n, int start) {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); ++i) {
            ret[i] = i ^ (i >> 1);
        }

        for (int i = 0; i < ret.size(); ++i) {
            if (ret[i] == start) {
                std::rotate(ret.begin(), ret.begin() + i, ret.end());
                break;
            }
        }

        return ret;
    }

    vector<int> circularPermutation(int n, int start) {
        //return graycode1(n, start);
        return graycode2(n, start);
    }
};
