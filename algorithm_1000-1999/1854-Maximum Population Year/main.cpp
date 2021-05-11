class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> counts(102, 0);
        for (const auto& log : logs) {
            ++counts[log[0] - 1950];
            --counts[log[1] - 1950];
        }

        int year = 0;
        for (int i = 1; i < counts.size(); ++i) {
            counts[i] += counts[i - 1];
            if (counts[year] < counts[i]) {
                year = i;
            }
        }

        return (year + 1950);
    }
};
