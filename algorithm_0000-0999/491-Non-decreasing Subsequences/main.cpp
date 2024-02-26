class Solution {
public:
    vector<vector<int>> dfs1(vector<int>& nums) {
        int n = nums.size();

        vector<int> seq;
        vector<vector<int>> seqs;
        std::function<void(int)> f = [&](int cur) {
            if (cur >= n) {
                if (seq.size() >= 2) {
                    seqs.push_back(seq);
                }
                return;
            }

            if (seq.empty() || seq.back() < nums[cur]) {
                seq.push_back(nums[cur]);
                f(cur + 1);
                seq.pop_back();

                f(cur + 1);
            }
            else if (seq.back() == nums[cur]) {
                seq.push_back(nums[cur]);
                f(cur + 1);
                seq.pop_back();
            }
            else {
                f(cur + 1);
            }
        };
        f(0);

        return seqs;
    }

    vector<vector<int>> dfs2(vector<int>& nums) {
        int n = nums.size();

        vector<int> seq;
        vector<vector<int>> seqs;
        std::function<void(int)> f = [&](int cur) {
            if (seq.size() >= 2) {
                seqs.push_back(seq);
            }
            if (cur >= n) {
                return;
            }

            unordered_set<int> visited;
            for (int i = cur; i < n; ++i) {
                if (!seq.empty() && seq.back() > nums[i]) { continue; }
                if (visited.emplace(nums[i]).second == false) { continue; }

                seq.push_back(nums[i]);
                f(i + 1);
                seq.pop_back();
            }
        };
        f(0);

        return seqs;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //return dfs1(nums);
        return dfs2(nums);
    }
};
