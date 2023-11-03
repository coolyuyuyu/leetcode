class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int i = 1;
        for (int t : target) {
            for (; i < t; ++i) {
                ret.push_back("Push");
                ret.push_back("Pop");
            }
            ret.push_back("Push");
            ++i;
        }

        return ret;
    }
};
