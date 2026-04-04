class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<int, int> m;
        for (char c : s) {
            ++m[c];
        }

        vector<int> cnts;
        for (const auto& [_, cnt] : m) {
            cnts.push_back(cnt);
        }
        std::sort(cnts.begin(), cnts.end());

        if (k > cnts.size()) {
            return 0;
        }
        return std::accumulate(cnts.begin(), cnts.end() - k, 0);
    }
};
