class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> char2cost;
        for (int i = 0, n = s.size(); i < n; ++i) {
            char2cost[s[i]] += cost[i];
        }

        long long sum = 0;
        long long maxCost = 0;
        for (const auto& [_, cost] : char2cost) {
            sum += cost;
            maxCost = std::max(maxCost, cost);
        }

        return sum - maxCost;
    }
};
