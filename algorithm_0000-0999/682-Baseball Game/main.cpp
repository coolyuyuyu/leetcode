class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (const string& op : ops) {
            switch (op.front()) {
                case 'C':
                    scores.pop_back();
                    break;
                case 'D':
                    scores.push_back(scores.back() * 2);
                    break;
                case '+':
                    scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
                    break;
                default:
                    scores.push_back(stoi(op, nullptr));
                    break;
            }
        }

        return std::accumulate(scores.begin(), scores.end(), 0);
    }
};
