class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        for (size_t prev = 0, i = 0; i < S.size(); ++i) {
            if (i + 1 == S.size() || S[i] != S[i + 1]) {
                if (prev + 2 <= i) {
                    ans.push_back({ (int)prev, (int)i });
                }

                prev = i + 1;
            }
        }

        return ans;
    }
};