class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> counts;
        for (int num : hand) {
            ++counts[num];
        }

        while (!counts.empty()) {
            auto itr = counts.begin();
            int num = counts.begin()->first;
            for (int i = 0; i < W; ++i) {
                if (itr == counts.end()) {
                    return false;
                }
                if (itr->first != num + i) {
                    return false;
                }

                --itr->second;
                auto itrCur = itr;
                ++itr;
                if (itrCur->second == 0) {
                    counts.erase(itrCur);
                }
            }
        }

        return true;
    }
};