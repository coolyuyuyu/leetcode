class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> suffixes(26);
        for (const string& idea : ideas) {
            suffixes[idea[0] - 'a'].insert(idea.substr(1));
        }

        long long ret = 0;
        for (int i = 0; i < suffixes.size(); ++i) {
            for (int j = i + 1; j < suffixes.size(); ++j) {
                int cnt1 = 0;
                for (const string& suffix : suffixes[i]) {
                    if (suffixes[j].find(suffix) == suffixes[j].end()) {
                        ++cnt1;
                    }
                }

                int cnt2 = 0;
                for (const string& suffix : suffixes[j]) {
                    if (suffixes[i].find(suffix) == suffixes[i].end()) {
                        ++cnt2;
                    }
                }

                ret += (cnt1 * cnt2);
            }
        }

        return ret * 2;
    }
};
