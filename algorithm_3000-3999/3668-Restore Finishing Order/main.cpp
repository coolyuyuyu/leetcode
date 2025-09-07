class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> s(friends.begin(), friends.end());
        vector<int> ret;
        for (int i : order) {
            if (s.find(i) != s.end()) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
