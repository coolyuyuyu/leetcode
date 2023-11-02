class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for (const string& op : operations) {
            switch (op.front()) {
            case '+':
                stk.push_back(stk[stk.size() - 2] + stk[stk.size() - 1]);
                break;
            case 'D':
                stk.push_back(stk.back() * 2);
                break;
            case 'C':
                stk.pop_back();
                break;
            default:
                stk.push_back(std::stoi(op));
                break;
            }
        }

        return std::accumulate(stk.begin(), stk.end(), 0);
    }
};
