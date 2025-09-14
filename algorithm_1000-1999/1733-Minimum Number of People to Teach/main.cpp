class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<bitset<501>> skills(1);
        for (const auto& langList : languages) {
            bitset<501> bs;
            for (int lang : langList) {
                bs.set(lang);
            }
            skills.push_back(bs);
        }

        unordered_set<int> users;
        for (const auto& friendship : friendships) {
            int u = friendship[0], v = friendship[1];
            if ((skills[u] & skills[v]).none()) {
                users.insert(u);
                users.insert(v);
            }
        }

        int ret = INT_MAX;
        for (int lang = 1; lang <= n; ++lang) {
            int cnt = 0;
            for (int user : users) {
                if (skills[user].test(lang) == false) {
                    ++cnt;
                }
            }
            ret = std::min(ret, cnt);
        }

        return ret;
    }
};
