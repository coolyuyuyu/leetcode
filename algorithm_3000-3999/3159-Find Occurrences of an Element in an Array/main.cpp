class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int m = nums.size(), n = queries.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2){ return queries[idx1] < queries[idx2]; });

        vector<int> ret(n);
        for (int j = 0, i = 0, cnt = 0; j < n; ++j) {
            for (; i < m && cnt < queries[indexes[j]]; ++i) {
                if (nums[i] == x) {
                    ++cnt;
                }
            }

            ret[indexes[j]] = (cnt == queries[indexes[j]] ?  (i - 1) : -1);
        }

        return ret;
    }
};
