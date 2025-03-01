class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> key2groups;
        for (const string& str : strings) {
            string key = str;
            int step = 'z' - key[0];
            for (char& c : key) {
                c = 'a' + ((c + step) - 'a') % 26;
            }
            key2groups[key].push_back(str);
        }

        vector<vector<string>> ret;
        for (const auto& [_, groups] : key2groups) {
            ret.push_back(groups);
        }

        return ret;
    }
};
