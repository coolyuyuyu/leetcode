class Solution {
public:
    string sortStr(const string& str) {
        vector<int> counts(26, 0);
        for (auto c : str) {
            ++counts[c - 'a'];
        }

        string result;
        result.reserve(str.size());

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < counts[i]; ++j) {
                result.push_back('a' + i);
            }
        }

        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_multimap<string, string> groups;
        for (vector<string>::const_iterator strIt = strs.begin(); strIt != strs.end(); ++strIt) {
            groups.emplace(sortStr(*strIt), *strIt);
        }

        vector<vector<string>> result;
        for (unordered_multimap<string, string>::const_iterator it = groups.begin(); it != groups.end(); ) {
            const string& key = it->first;
            result.push_back(vector<string>());
            do {
                result.back().push_back(it->second);
                ++it;
            } while (it != groups.end() && key == it->first);
        }
        
        return result;
    }
};