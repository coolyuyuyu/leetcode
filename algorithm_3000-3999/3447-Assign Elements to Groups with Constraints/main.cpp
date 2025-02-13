class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int mx = *std::max_element(groups.begin(), groups.end());

        int assign[mx + 1];
        std::fill(assign, assign + mx + 1, -1);
        for (int i = 0; i < elements.size(); ++i) {
            int x = elements[i];
            if (x > mx) { continue; }
            if (assign[x] != -1) { continue; }
            for (; x <= mx; x += elements[i]) {
                if (assign[x] == -1) {
                    assign[x] = i;
                }
            }
        }

        vector<int> ret(groups.size());
        for (int i = 0; i < ret.size(); ++i) {
            ret[i] = assign[groups[i]];
        }

        return ret;
    }
};
