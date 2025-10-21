class Solution {
public:
    int maxDistance(vector<string>& words) {
        int n = words.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i] != words[j]) {
                    ret = std::max(ret, j - i + 1);
                }
            }
        }

        return ret;
    }
};
