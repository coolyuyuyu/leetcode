class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ret(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            vector<int> nodes1 = {queries[i][0]};
            while (nodes1.back() != 1) {
                nodes1.push_back(nodes1.back() / 2);
            }
            vector<int> nodes2 = {queries[i][1]};
            while (nodes2.back() != 1) {
                nodes2.push_back(nodes2.back() / 2);
            }
            while (!nodes1.empty() && !nodes2.empty() && nodes1.back() == nodes2.back()) {
                nodes1.pop_back();
                nodes2.pop_back();
            }

            ret[i] = nodes1.size() + nodes2.size() + 1;

        }

        return ret;
    }
};
