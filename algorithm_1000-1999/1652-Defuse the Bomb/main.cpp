class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len = code.size();

        vector<int> ret(len, 0);
        if (k == 0) {
            return ret;
        }

        partial_sum(code.begin(), code.end(), code.begin());
        if (0 < k) {
            for (size_t i = 0; i < len; ++i) {
                ret[i] -= code[i];

                if (len <= (i + k)) {
                    ret[i] += code[len - 1];
                    ret[i] += code[k - (len - i)];
                }
                else {
                    ret[i] += code[i + k];
                }
            }
        }
        else {
            k = -k;
            for (size_t i = 0; i < len; ++i) {
                if (0 < i) {
                    ret[i] += code[i - 1];
                }

                if (k < i) {
                    ret[i] -= code[i - 1 - k];
                }

                if (i < k) {
                    ret[i] += (code[len - 1] - code[len - k + i - 1]);
                }
            }
        }


        return ret;
    }
};
