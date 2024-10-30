class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<vector<string>> paths;
        for (const string& s: folder) {
            vector<string> names;
            string name;
            for (int i = 1; i <= s.size(); ++i) {
                if (i == s.size() || s[i] == '/') {
                    names.push_back(name);
                    name.clear();
                }
                else {
                    name += s[i];
                }
            }
            paths.push_back(names);
        }
        std::sort(paths.begin(), paths.end());

        vector<string> ret;
        for (int i = 0, n = paths.size(); i < n;) {
            int j = i + 1;
            for (; j < n && std::equal(paths[i].begin(), paths[i].end(), paths[j].begin()); ++j) {
                ;
            }

            string s;
            for (const string name : paths[i]) {
                s += "/";
                s += name;
            }
            ret.push_back(s);

            i = j;
        }



        return ret;
    }
};
