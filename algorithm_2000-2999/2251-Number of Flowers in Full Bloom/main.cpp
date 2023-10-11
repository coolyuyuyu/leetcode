class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> diffs;
        for (const auto& flower : flowers) {
            ++diffs[flower[0]];
            --diffs[flower[1] + 1];
        }

        int n = people.size();
        vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int index1, int index2) { return people[index1] < people[index2]; });

        vector<int> ret(n);
        int sum = 0;
        auto itr = diffs.begin();
        for (int i = 0; i < n; ++i) {
            for (; itr != diffs.end() && itr->first <= people[indexes[i]]; ++itr) {
                sum += itr->second;
            }

            ret[indexes[i]] = sum;
        }

        return ret;
    }
};
