class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int bktSize = std::sqrt(n);

        vector<int> qIdxes(queries.size());
        std::iota(qIdxes.begin(), qIdxes.end(), 0);

        std::sort(
            qIdxes.begin(), qIdxes.end(),
            [&](auto& idx1, auto& idx2) {
                int l1 = queries[idx1][0], r1 = queries[idx1][1];
                int l2 = queries[idx2][0], r2 = queries[idx2][1];
                return std::make_pair(l1 / bktSize, r1) < std::make_pair(l2 / bktSize, r2);
            });

        unordered_map<int, int> num2freq;
        unordered_map<int, set<int>> freq2nums;
        int maxFreq = 0;
        std::function<void(int)> insertNum = [&](int num) {
            if (num2freq[num]) {
                freq2nums[num2freq[num]].erase(num);
            }
            ++num2freq[num];
            freq2nums[num2freq[num]].insert(num);
            if (num2freq[num] > maxFreq) {
                ++maxFreq;
            }
        };
        std::function<void(int)> removeNum = [&](int num) {
            assert(num2freq[num] > 0);
            freq2nums[num2freq[num]].erase(num);
            --num2freq[num];
            if (num2freq[num]) {
                freq2nums[num2freq[num]].insert(num);
            }
            if (freq2nums[maxFreq].empty()) {
                --maxFreq;
            }
        };
        std::function<int(int)> answer = [&](int threshold) {
            if (maxFreq < threshold) {
                return -1;
            }
            else {
                return *(freq2nums[maxFreq].begin());
            }
        };

        int curL = 0, curR = -1;
        vector<int> ret(qIdxes.size());
        for (int qIdx : qIdxes) {
            const auto& query = queries[qIdx];
            int l = query[0], r = query[1], threshold = query[2];
            while (curR < r) {
                insertNum(nums[++curR]);
            }
            while (r < curR) {
                removeNum(nums[curR--]);
            }
            while (curL < l) {
                removeNum(nums[curL++]);
            }
            while (l < curL) {
                insertNum(nums[--curL]);
            }

            ret[qIdx] = answer(threshold);
        }

        return ret;
    }
};
