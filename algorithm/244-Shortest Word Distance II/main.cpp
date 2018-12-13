class WordDistance {
public:
    WordDistance(const vector<string>& words) {
        for (size_t i = 0; i < words.size(); ++i) {
            m_indexesMap[words[i]].push_back(i);
        }
    }

    int shortest(const string& word1, const string& word2) {
        const vector<size_t>& indexes1 = m_indexesMap[word1];
        const vector<size_t>& indexes2 = m_indexesMap[word2];

        size_t minDistance = numeric_limits<size_t>::max();
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

        return minDistance;
    }

private:
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

    unordered_map<string, vector<size_t>> m_indexesMap;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */