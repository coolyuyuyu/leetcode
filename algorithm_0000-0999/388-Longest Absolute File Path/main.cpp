class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();

        int ret = 0;

        vector<int> stk;
        for (int i = 0; i < n; ++i) {
            int depth = 0;
            for (; i < n && input[i] == '\t'; ++i) {
                ++depth;
            }
            while (stk.size() > depth) {
                stk.pop_back();
            }

            bool file = false;
            stk.push_back(0);
            for (;i < n && input[i] != '\n'; ++i) {
                if (input[i] == '.') {
                    file = true;
                }
                ++stk.back();
            }

            if (file) {
                int len = std::accumulate(stk.begin(), stk.end(), 0) + stk.size() - 1;
                ret = std::max(ret, len);
            }
        }

        return ret;
    }
};
