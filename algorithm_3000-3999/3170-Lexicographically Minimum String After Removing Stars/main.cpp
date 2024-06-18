class Solution {
public:
    string clearStars(string s) {
        auto comp = [](const pair<char, int>& p1, const pair<char, int>& p2) {
            const auto& [c1, idx1] = p1;
            const auto& [c2, idx2] = p2;
            return c1 > c2 || (c1 == c2 && idx1 < idx2);
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '*' && !pq.empty()) {
                auto [_, idx] = pq.top();
                pq.pop();
                s[idx] = '\0';
            }
            else if (isalpha(c)) {
                pq.emplace(c, i);
            }
        }

        string ret;
        for (char c : s) {
            if (isalpha(c)) {
                ret += c;
            }
        }

        return ret;
    }
};
