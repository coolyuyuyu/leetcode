class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        // m[num]: the length of the longest subsequence as arithmetic sequence ending at num
        unordered_map<int, int> m;

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            auto itr = m.find(arr[i] - difference);
            if (itr != m.end()) {
                m[arr[i]] = itr->second + 1;
            }
            else {
                m[arr[i]] = 1;
            }

            ret = std::max(ret, m[arr[i]]);
        }

        return ret;
    }
};
