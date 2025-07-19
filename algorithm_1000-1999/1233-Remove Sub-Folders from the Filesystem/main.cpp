class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        vector<string> ret;

        unordered_set<string_view> s(folders.begin(), folders.end());
        for (const string& folder : folders) {
            bool isSub = false;
            for (int i = 1; i < folder.size(); ++i) {
                    if (folder[i] == '/' && s.find(string_view(folder.c_str(), i)) != s.end()) {
                    isSub = true;
                }
            }

            if (!isSub) {
                ret.push_back(folder);
            }
        }

        return ret;
    }
};
