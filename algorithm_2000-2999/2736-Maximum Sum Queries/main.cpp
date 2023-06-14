class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < nums1.size(); ++i) {
            nums.emplace_back(nums1[i], nums2[i]);
        }
        std::sort(
            nums.rbegin(), nums.rend(), 
            [](const auto& p1, const auto& p2) {
                return (p1.first + p1.second) < (p2.first + p2.second);
            });

        map<int, set<pair<int, int>>> m; // x -> {<y, index>, ...}
        for (int i = 0; i < queries.size(); ++i) {
            int x = queries[i][0], y = queries[i][1];
            m[x].emplace(y, i);
        }

        vector<int> ret(queries.size(), -1);
        for (const auto& num : nums) {
            int num1 = num.first, num2 = num.second, sum = num.first + num.second;
            for (auto itr1 = m.begin(); itr1 != m.end() && itr1->first <= num1;) {
                for(auto itr2 = itr1->second.begin(); itr2 != itr1->second.end() && itr2->first <= num2; itr2 = itr1->second.erase(itr2)) {
                    ret[itr2->second] = sum;
                }

                if (itr1->second.empty()) {
                    itr1 = m.erase(itr1);
                }
                else {
                    ++itr1;
                }
            }
        }
        
        return ret;
    }
};
