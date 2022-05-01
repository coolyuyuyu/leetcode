class Solution {
public:
    // Time: O(NlogN), Space: O(N)
    int bySort(vector<vector<int>>& logs) {
        vector<int> years;
        for (const auto& log : logs) {
            years.push_back(log[0]);
            years.push_back(-(log[1] - 1));
        }

        auto comp = [](int y1, int y2) -> bool {
            if (abs(y1) != abs(y2)) {
                return abs(y1) < abs(y2);
            }
            else {
                return y1 > y2;
            }
        };
        std::sort(years.begin(), years.end(), comp);

        int year = 0, popcnt = 0;
        for (size_t curPopCnt = 0, maxPopCnt = 0, i = 0; i < years.size(); ++i) {
            curPopCnt += (0 < years[i] ? 1 : -1);
            if (maxPopCnt < curPopCnt) {
                maxPopCnt = curPopCnt;
                year = years[i];
            }
        }

        return abs(year);
    }

    // Time: O(N), Space: O(1)
    int byCount(vector<vector<int>>& logs) {
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

    int maximumPopulation(vector<vector<int>>& logs) {
        //return bySort(logs);
        return byCount(logs);
    }
};
