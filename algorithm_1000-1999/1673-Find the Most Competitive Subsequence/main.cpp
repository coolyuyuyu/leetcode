class Solution {
public:
    typedef vector<int> Sequence;

    static bool compareSeq(const Sequence& seq1, const Sequence& seq2) {
        size_t len = min(seq1.size(), seq2.size());
        for (size_t i = 0; i < len; ++i) {
            if (seq1[i] == seq2[i]) {
                continue;
            }
            else {
                return seq1[i] < seq2[i];
            }
        }

        return seq1.size() < seq2.size();
    }

    void allSubsequence(vector<int>& nums, int depth, int k, Sequence& seq, function<void(const Sequence&)> f = nullptr) {
        if (seq.size() == k) {
            if (f) {
                f(seq);
            }
            return;
        }

        if (nums.size() <= depth) {
            return;
        }
        else if ((seq.size() + nums.size() - depth) < k) {
            return;
        }

        seq.push_back(nums[depth]);
        allSubsequence(nums, depth + 1, k, seq, f);
        seq.pop_back();
        allSubsequence(nums, depth + 1, k, seq, f);
    }

    vector<int> mostCompetitive_BruteForceSort(vector<int>& nums, int k) {
        vector<Sequence> subsequences;
        function<void(const vector<int>&)> f = [&subsequences](const Sequence& seq) -> void {
            subsequences.push_back(seq);
        };

        Sequence subsequence;
        allSubsequence(nums, 0, k, subsequence, f);

        sort(subsequences.begin(), subsequences.end(), compareSeq);

        return subsequences.front();
    }

    vector<int> mostCompetitive_BruteForceMin(vector<int>& nums, int k) {
        Sequence minSubSequence(nums.begin(), nums.begin() + k);
        function<void(const vector<int>&)> f = [&minSubSequence](const Sequence& seq) -> void {
            if (compareSeq(seq, minSubSequence)) {
                minSubSequence = seq;
            }
        };

        Sequence subsequence;
        allSubsequence(nums, 0, k, subsequence, f);

        return minSubSequence;
    }

    vector<int> mostCompetitive_Stack(vector<int>& nums, int k) {
        vector<int> stk;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[i] < stk.back() && k < (stk.size() + nums.size() - i)) {
                stk.pop_back();
            }

            if (stk.size() < k) {
                stk.push_back(nums[i]);
            }
        }

        return stk;
    }

    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // TLE
        // Time: O(2^N + N(2^N)), Space(2^N * K)
        // return mostCompetitive_BruteForceSort(nums, k);

        // TLE
        // Time: O(2^N), Space(K)
        // return mostCompetitive_BruteForceMin(nums, k);

        // Time: O(N), Space: O(K)
        return mostCompetitive_Stack(nums, k);
    }
};