class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();

        set<int> ss;
        ss.insert(-1);
        ss.insert(n);

        long long cnt = 0;
        for (int t = 0; t < n; ++t) {
            auto itr = ss.insert(order[t]).first;
            auto pre = std::prev(itr);
            auto nxt = std::next(itr);
            int lft = *itr - *pre;
            int rht = *nxt - *itr;

            cnt += 1LL * lft * rht;
            if (cnt >= k) {
                return t;
            }
        }

        return -1;
    }
};
