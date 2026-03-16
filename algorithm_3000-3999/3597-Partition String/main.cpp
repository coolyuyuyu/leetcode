class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ret;;

        unordered_set<string> seen;
        string seg;
        for (char c : s) {
            seg += c;
            if (seen.insert(seg).second) {
                ret.push_back(seg);
                seg.clear();
            }
        }

        return ret;
    }
};
