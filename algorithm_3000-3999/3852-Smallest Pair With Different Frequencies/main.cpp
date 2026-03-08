class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        for (auto itr1 = cnts.begin(); itr1 != cnts.end(); ++itr1) {
            auto [x, cnt1] = *itr1;
            for (auto itr2 = std::next(itr1); itr2 != cnts.end(); ++itr2) {
                auto [y, cnt2] = *itr2;
                if (cnt1 != cnt2) {
                    return {x, y};
                }
            }
        }

        return {-1, -1};
    }
};
