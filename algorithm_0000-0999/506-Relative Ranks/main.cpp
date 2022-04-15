class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& scores) {
        vector<size_t> indexes(scores.size());
        for (size_t i = 0; i < indexes.size(); ++i){
            indexes[i] = i;
        }
        std::sort(indexes.begin(), indexes.end(), [&](size_t a, size_t b){ return scores[a] < scores[b]; });

        vector<string> ranks(indexes.size());
        if (0 < indexes.size())
            ranks[indexes[indexes.size() - 1]] = "Gold Medal";
        if (1 < indexes.size())
            ranks[indexes[indexes.size() - 2]] = "Silver Medal";
        if (2 < indexes.size()) {
            ranks[indexes[indexes.size() - 3]] = "Bronze Medal";
            for (size_t i = indexes.size() - 3; 0 < i--;) {
                ranks[indexes[i]] = std::to_string(indexes.size() - i);
            }
        }

        return ranks;
    }
};
