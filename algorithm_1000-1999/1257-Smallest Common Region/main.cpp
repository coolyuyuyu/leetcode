class Solution {
public:
    int depth(string region, const unordered_map<string, string>& parents) {
        int d = 0;
        for (auto itr = parents.find(region); itr != parents.end(); itr = parents.find(region)) {
            ++d;
            region = itr->second;
        }

        return d;
    }

    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parents;
        for (vector<string>& l : regions) {
            for (size_t i = 1; i < l.size(); ++i) {
                parents[l[i]] = l[0];
            }
        }

        int depth1 = depth(region1, parents), depth2 = depth(region2, parents);
        if (depth2 < depth1) {
            swap(depth1, depth2);
            swap(region1, region2);

        }

        for (int i = depth2 - depth1; 0 < i; --i) {
            region2 = parents[region2];
        }
        while (region1 != region2) {
            region1 = parents[region1];
            region2 = parents[region2];
        }

        return region1;
    }
};