class Solution {
public:
    void recursive1(const vector<int>& nums, int start, vector<int>& seq, vector<vector<int>>& seqs) {
        if (nums.size() <= start) {
            if (1 < seq.size()) {
                seqs.emplace_back(seq.begin(), seq.end());
            }
            return;
        }

        if (seq.empty() || seq.back() < nums[start]) {
            recursive1(nums, start + 1, seq, seqs);

            seq.push_back(nums[start]);
            recursive1(nums, start + 1, seq, seqs);
            seq.pop_back();
        }
        else if (seq.back() == nums[start]) {
            seq.push_back(nums[start]);
            recursive1(nums, start + 1, seq, seqs);
            seq.pop_back();
        }
        else {
            recursive1(nums, start + 1, seq, seqs);
        }
    }

    void recursive2(const vector<int>& nums, int start, vector<int>& seq, vector<vector<int>>& seqs) {
        if (1 < seq.size()) {
            seqs.emplace_back(seq.begin(), seq.end());
        }
        if (nums.size() <= start) {
            return;
        }

        unordered_set<int> visited;
        for (int i = start; i < nums.size(); ++i) {
            if (visited.find(nums[i]) != visited.end()) {
                continue;
            }

            if (seq.empty() || seq.back() <= nums[i]) {
                visited.insert(nums[i]);

                seq.push_back(nums[i]);
                recursive2(nums, i + 1, seq, seqs);
                seq.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> seq;
        vector<vector<int>> seqs;
        //recursive1(nums, 0, seq, seqs);
        recursive2(nums, 0, seq, seqs);
        return seqs;
    }
};

// 0 1111 222 33

// 0 1111
// 0 .111
// 0 ..11
// 0 ...1
// 0 ....
