class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        unordered_set<int> s;
        int mx = INT_MIN;
        for (int num : nums) {
            mx = std::max(mx, num);
            if (num < 0 || s.find(num) != s.end()) { continue; }
            sum += num;
            s.insert(num);
        }

        return mx < 0 ? mx : sum;
    }
};
