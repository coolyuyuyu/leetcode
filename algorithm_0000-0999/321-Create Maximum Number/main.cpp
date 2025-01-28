class Solution {
public:
    // TLE, Time: O(m*n*k)
    vector<int> byDP(vector<int>& nums1, vector<int>& nums2, int k) {
        int M = nums1.size(), N = nums2.size(), K = k;

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // dp[i][j][k]: the maximum number of length k digits created from nums1[1:i] and nums2[1:j]
        string dp[M + 1][N + 1][K + 1];

        for (int i = 1; i <= M; ++i) {
            for(int k = 1;k <= min(i, K); ++k) {
                dp[i][0][k] = max(dp[i-1][0][k], dp[i - 1][0][k - 1] + to_string(nums1[i]));
            }
        }
        for (int j = 1; j <= N; ++j) {
            for(int k = 1;k <= min(j, K); ++k) {
                dp[0][j][k] = max(dp[0][j - 1][k], dp[0][j - 1][k - 1] + to_string(nums2[j]));
            }
        }
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int k = 1; k <= std::min(i + j, K); ++k) {
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k - 1] + std::to_string(nums1[i]));
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k - 1] + std::to_string(nums2[j]));
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k]);
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k]);
                }
            }
        }

        vector<int> ret;
        for (char c : dp[M][N][K]) {
            ret.push_back(c - '0');
        }

        return ret;
    }

    // Time: O(k * (m + n))
    vector<int> byStk(vector<int>& nums1, vector<int>& nums2, int k) {
        std::function<vector<int>(const vector<int>&, int)> findMax = [](const vector<int>& nums, int k) {
            vector<int> ret;
            for (int i = 0, drop = nums.size() - k; i < nums.size(); ++i) {
                while (!ret.empty() && nums[i] > ret.back() && drop > 0) {
                    --drop;
                    ret.pop_back();
                }
                ret.push_back(nums[i]);
            }
            ret.erase(ret.begin() + k, ret.end());
            return ret;
        };

        std::function<vector<int>(const vector<int>&, const vector<int>&)> merge = [](const vector<int>& seq1, const vector<int>& seq2) {
            vector<int> ret(seq1.size() +  seq2.size());
            for (int i = 0, j = 0, k = 0; i < seq1.size() || j < seq2.size(); ++k) {
                if (std::lexicographical_compare(seq1.begin() + i, seq1.end(), seq2.begin() + j, seq2.end())) {
                    ret[k] = seq2[j++];
                }
                else {
                    ret[k] = seq1[i++];
                }
            }

            return ret;
        };

        vector<int> ret;
        for (int i = 0; i <= std::min<int>(nums1.size(), k); ++i) {
            //if (i > nums1.size()) { continue; }
            if (k - i > nums2.size()) { continue; }
            vector<int> seq1 = findMax(nums1, i);
            vector<int> seq2 = findMax(nums2, k - i);
            ret = std::max(ret, merge(seq1, seq2));
        }

        return ret;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //return byDP(nums1, nums2, k);
        return byStk(nums1, nums2, k);
    }
};
