class Solution {
public:
    int distributeCandies(vector<int>& types) {
        size_t halfCnt = types.size() / 2;
        unordered_set<int> s;
        for (int type : types) {
            s.insert(type);
            if (halfCnt <= s.size()) {
                return halfCnt;
            }
        }

        return s.size();
    }
};
