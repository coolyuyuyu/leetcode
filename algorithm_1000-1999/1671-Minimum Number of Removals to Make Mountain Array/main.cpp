class Solution {
public:
    template<class InputIterator, class OutputIterator>
    OutputIterator computeLIS(InputIterator first, InputIterator last, OutputIterator result) {
        vector<int> lis;
        for (; first != last; ++first, ++result) {
            vector<int>::iterator itr;
            if (lis.empty() || lis.back() < *first) {
                lis.push_back(*first);
                itr = std::prev(lis.end());
            }
            else {
                itr = std::lower_bound(lis.begin(), lis.end(), *first);
                *itr = *first;
            }
            *result = std::distance(lis.begin(), itr) + 1;
        }

        return result;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> lftLIS(n);
        computeLIS(nums.begin(), nums.end(), lftLIS.begin());

        vector<int> rhtLIS(n);
        computeLIS(nums.rbegin(), nums.rend(), rhtLIS.rbegin());

        int ret = INT_MAX;
        for (int i = 0; i + 1 < n; ++i) {
            if (lftLIS[i] >= 2 && rhtLIS[i] >= 2) {
                int len = lftLIS[i] + rhtLIS[i] - 1;
                ret = std::min(ret, n - len);
            }
        }

        return ret;
    }
};
