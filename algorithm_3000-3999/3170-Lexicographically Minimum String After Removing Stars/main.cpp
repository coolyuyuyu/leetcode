class Solution {
public:
    string clearStars(string s) {
        auto comp = [&](int i1, int i2) {
            return s[i1] > s[i2] || (s[i1] == s[i2] && i1 < i2);
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] == '*') {
                s[pq.top()] = '*';
                pq.pop();
            }
            else {
                pq.push(i);
            }
        }

        string ret;
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] == '*') { continue; }
            ret.push_back(s[i]);
        }

        return ret;
    }
};
