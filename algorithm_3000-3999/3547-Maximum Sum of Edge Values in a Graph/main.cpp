class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        bool cycle = edges.size() == n;

        list<int> l;
        l.push_back(n--);
        for (; n > 0; --n) {
            if (l.front() > l.back()) {
                l.push_front(n);
            }
            else {
                l.push_back(n);
            }
        }

        long long ret = 0;
        for (auto pre = l.begin(), cur = std::next(pre); cur != l.end(); cur = std::next(pre)) {
            ret += 1LL * (*pre) * (*cur);
            pre = cur;
        }   
        if (cycle) {
            ret += l.front() * l.back();
        }

        return ret;
    }
};
