class Solution {
public:
    int colors[100000];
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int num = 0;

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int index = queries[i][0], color = queries[i][1];
            if (colors[index] != 0) {
                if (1 <= index && colors[index - 1] == colors[index]) {
                    num--;
                }
                if ((index + 1) < n && colors[index] == colors[index + 1]) {
                    num--;
                }
            }
            colors[index] = color;
            if (1 <= index && colors[index - 1] == colors[index]) {
                ++num;
            }
            if ((index + 1) < n && colors[index] == colors[index + 1]) {
                ++num;
            }

            ret[i] = num;
        }

        return ret;
    }
};
