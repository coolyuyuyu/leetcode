class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<size_t> indexes;(names.size());
        for (size_t i = 0; i < names.size(); ++i) {
            indexes.push_back(i);
        }
        auto comp = [&](size_t a, size_t b) {
            return (heights[a] < heights[b]);
        };
        std::sort(indexes.begin(), indexes.end(), comp);

        vector<string> ret(names.size());
        for (size_t i = 0; i < indexes.size(); ++i) {
            ret[ret.size() - i - 1] = names[indexes[i]];
        }

        return ret;
    }
};
