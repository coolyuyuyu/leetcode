class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for (const string& word : words) {
            for (size_t pos = text.find(word); pos != string::npos; pos = text.find(word, pos + 1)) {
                ans.push_back({int(pos), int(pos + word.size() - 1)});
            }
        }
        std::sort(ans.begin(), ans.end());

        return ans;
    }
};
