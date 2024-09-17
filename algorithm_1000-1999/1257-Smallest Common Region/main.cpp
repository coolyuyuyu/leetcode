class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parents;
        for (const auto& list : regions) {
            for (int i = 1; i < list.size(); ++i) {
                parents[list[i]] = list[0];
            }
        }

        std::function<int(const string& s)> computeDepth = [&](string s) {
            int depth = 0;
            for (auto itr = parents.find(s); itr != parents.end(); itr = parents.find(s)) {
                ++depth;
                s = itr->second;
            }

            return depth;
        };
        int depth1 = computeDepth(region1), depth2 = computeDepth(region2);
        auto& region = depth1 > depth2 ? region1 : region2;
        for (int diff = abs(depth1 - depth2); 0 < diff--;) {
            region = parents[region];
        }

        while (region1 != region2) {
            region1 = parents[region1];
            region2 = parents[region2];
        }

        return region1;
    }
};
