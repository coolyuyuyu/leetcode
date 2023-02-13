class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < queries.size(); ++i) {
            m[queries[i][0] ^ queries[i][1]].push_back(i);
        }

        vector<vector<int>> ret(queries.size(), {-1, -1});
        for (int len = 1; len <= 30; ++len) {
            int num = 0;
            for (int i = 0; i < s.size(); ++i) {
                num = (num << 1) + s[i] - '0';
                if (len <= i) {
                    num -= (s[i - len] == '1' ? (1 << len) : 0);
                }

                if (m.find(num) != m.end()) {
                    for (int index : m[num]) {
                        ret[index] = {i - len + 1, i};
                    }
                    //m.erase(num);
                    m[num].clear();
                }
            }
        }

        return ret;
    }
};
