class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> citys;
        for (const auto& path : paths) {
            const string& from = path[0];
            const string& to = path[1];
            citys.insert(from);
            citys.insert(to);
        }

        for (const auto& path : paths) {
            const string& from = path[0];
            citys.erase(from);
        }

        return *(citys.begin());
    }
};
