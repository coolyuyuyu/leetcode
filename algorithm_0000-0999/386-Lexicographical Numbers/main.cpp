class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret = {1};
        while (ret.size() < n) {
            int v = ret.back();
            if (v * 10 <= n) {
                v *= 10;
            }
            else {
                while (v % 10 == 9 || v >= n) {
                    v /= 10;
                }
                v += 1;
            }
            ret.push_back(v);
        }

        return ret;
    }
};
