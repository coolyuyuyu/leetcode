class Solution {
public:
    size_t searchInsert(const vector<size_t> nums, size_t target) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    size_t minDiff(const vector<size_t>& nums, size_t target) {
        assert(!nums.empty());

        size_t index = searchInsert(nums, target);
        if (nums.size() <= index) {
            return target - nums.back();
        }
        else {
            size_t diff = nums[index] - target;
            if (1 <= index) {
                diff = min(diff, target - nums[index - 1]);
            }
            return diff;
        }
    }

    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        size_t minDistance = numeric_limits<size_t>::max();
        if (word1 == word2) {
            vector<size_t> indexes;
            for (size_t i = 0; i < words.size(); ++i) {
                if (words[i] == word1) {
                    indexes.push_back(i);
                }
            }

            for (size_t i = 1; i < indexes.size(); ++i) {
                minDistance = min(minDistance, indexes[i] - indexes[i - 1]);
            }
        }
        else {
            vector<size_t> indexes1, indexes2;
            for (size_t i = 0; i < words.size(); ++i) {
                if (words[i] == word1) {
                    indexes1.push_back(i);
                }
                else if (words[i] == word2) {
                    indexes2.push_back(i);
                }
            }

            if (indexes1.size() <= indexes2.size()) {
                for (size_t index1 : indexes1) {
                    minDistance = min(minDistance, minDiff(indexes2, index1));
                }
            }
            else {
                for (size_t index2 : indexes2) {
                    minDistance = min(minDistance, minDiff(indexes1, index2));
                }
            }
        }

        return minDistance;
    }
};