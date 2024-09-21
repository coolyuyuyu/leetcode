class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret = {1};
        while (ret.size() < n) {
            int val = ret.back();
            if (val != 0 && val * 10 <= n) {
                val *= 10;
            }
            else {
                while (val % 10 == 9 || val >= n) {
                    val /= 10;
                }
                ++val;
            }

            ret.push_back(val);
        }

        return ret;
    }
};
