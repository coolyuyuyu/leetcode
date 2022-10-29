class Solution {
public:
    void recursive(const vector<int>& nums, size_t depth, vector<int>& sub, vector<vector<int>>& subs) {
        if (1 < sub.size()) {
            subs.push_back(sub);
        }
        if (nums.size() <= depth) {
            return;
        }

        unordered_set<int> s;
        for (size_t i = depth; i < nums.size(); ++i) {
            if (!sub.empty() && nums[i] < sub.back()) {
                continue;
            }
            if (s.find(nums[i]) != s.end()) {
                continue;
            }
            s.emplace(nums[i]);

            sub.push_back(nums[i]);
            recursive(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }

    void recursive2(const vector<int>& nums, size_t depth, vector<int>& sub, vector<vector<int>>& subs) {
        if (nums.size() <= depth) {
            if (1 < sub.size()) {
                subs.push_back(sub);
            }
            return;
        }

        if (sub.empty() || sub.back() <= nums[depth]) {
            sub.push_back(nums[depth]);
            recursive2(nums, depth + 1, sub, subs);
            sub.pop_back();
        }

        if (sub.empty() || sub.back() != nums[depth]) {
            recursive2(nums, depth + 1, sub, subs);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> subs;
        recursive2(nums, 0, sub, subs);
        return subs;
    }
};
