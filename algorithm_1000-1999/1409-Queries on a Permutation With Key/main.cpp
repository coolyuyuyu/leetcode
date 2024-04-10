class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        list<int> perm;
        for (int i = 1; i <= m; ++i) {
            perm.push_back(i);
        }

        int n = queries.size();
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            int pos = 0;
            auto itr = perm.begin();
            while (*itr != queries[i]) {
                ++pos;
                ++itr;
            }

            ret[i] = pos;
            perm.erase(itr);
            perm.push_front(queries[i]);
        }

        return ret;
    }
};
