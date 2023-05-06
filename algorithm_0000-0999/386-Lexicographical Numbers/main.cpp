class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for (int i = 0; ret.size() < n;) {
            if (i != 0 && (i * 10) <= n) {
                i *= 10;
            }
            else {
                while ((i % 10) == 9 || n <= i ) {
                    i /= 10;
                }
                ++i;
            }

            ret.push_back(i);
        }

        return ret;
    }
};
