class Solution {
public:
    bool isSubsequence1(const string& s, const string& t) {
        size_t i = 0, j = 0, m = s.size(), n = t.size();
        while (i < m && j < n) {
            if (s[i] != t[j]) {
                ++j;
            }
            else {
                ++i;
                ++j;
            }
        }

        return m <= i;
    }

    size_t searchInsert(const vector<size_t>& nums, size_t target) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else if (nums[mid] == target) {
                hi = mid;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    bool findNext(const vector<size_t>& nums, size_t target, size_t& result) {
        size_t index = searchInsert(nums, target + 1);
        if (nums.size() <= index) {
            return false;
        }

        result = nums[index];
        return true;
    }

    // Preferable when we have a large number of s for a single t
    bool isSubsequence2(const string& s, const vector<vector<size_t>>& indexArrays) {
        size_t prevJ = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            const vector<size_t>& indexArray = indexArrays[s[i] - 'a'];
            if (i == 0) {
                if (indexArray.empty()) {
                    return false;
                }
                prevJ = indexArray.front();
            }
            else {
                if (!findNext(indexArray, prevJ, prevJ)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isSubsequence(string s, string t) {
        //return isSubsequence1(s, t);

        vector<vector<size_t>> indexArrays(26);
        for (size_t j = 0; j < t.size(); ++j) {
            indexArrays[t[j] - 'a'].push_back(j);
        }
        return isSubsequence2(s, indexArrays);
    }
};