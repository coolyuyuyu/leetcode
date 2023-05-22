class Solution {
public:
    // Time: O(n + mlogm + k), Space: O(m + k), m: number of distinct num
    vector<int> bySort(const vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int num : nums) {
            ++freqs[num];
        }

        vector<pair<int, int>> pairs(freqs.begin(), freqs.end());
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second < p2.second;
        };
        std::sort(pairs.begin(), pairs.end(), comp);

        vector<int> ret(k);
        for (int i = 0; i < k; ++i) {
            ret[i] = pairs[pairs.size() - i - 1].first;
        }

        return ret;
    }

    // Time: O(n + m + k), Space: O(n + m + k), m: number of distinct num
    vector<int> byBucket(const vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int num : nums) {
            ++freqs[num];
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto [num, freq] : freqs) {
            buckets[freq].push_back(num);
        }

        vector<int> ret(k);
        for (int m = buckets.size(), i = 0; 0 < m-- && i < k;) {
            for (int num : buckets[m]) {
                ret[i++] = num;
            }
        }

        return ret;
    }

    // Time: O(n + mlogk + k), Space: O(m + k), m: number of distinct num
    vector<int> byHeap(const vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int num : nums) {
            ++freqs[num];
        }

        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (const auto [num, freq] : freqs) {
            pq.emplace(num, freq);
            if (k < pq.size()) {
                pq.pop();
            }
        }

        vector<int> ret(k);
        for (; !pq.empty(); pq.pop()) {
            ret[--k] = pq.top().first;
        }

        return ret;
    }

    // Time: O(n + mlogn + m), Space: O(m + k), m: number of distinct num
    vector<int> byBinarySearch(const vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int num : nums) {
            ++freqs[num];
        }

        auto countFreqGE = [&](int freq) {
            return std::count_if(
                freqs.begin(), freqs.end(),
                [&](const pair<int, int>& p) {
                    return freq <= p.second;
                });
        };

        int lo = 0, hi = nums.size() + 1;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (k <= countFreqGE(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        vector<int> ret(k);
        for (const auto [num, freq] : freqs) {
            if (lo <= freq) {
                ret[--k] = num;
            }
        }

        return ret;
    }

    // ---

    void quickselect(vector<pair<int, int>>& pairs, int lo, int hi, int k) {
        assert(k <= (hi - lo + 1));

        // S S S S S M M M X X X L L L
        //           i     x   j
        int i = lo, j = hi, x = lo;
        int pivot = pairs[lo + (hi - lo) / 2].second;
        while (x <= j) {
            if (pairs[x].second < pivot) {
                std::swap(pairs[i], pairs[x]);
                ++i;
                ++x;
            }
            else if (pairs[x].second == pivot) {
                ++x;
            }
            else {
                std::swap(pairs[x], pairs[j]);
                --j;
            }
        }

        // S S S M M M M L L L
        //       i     j
        if (k <= (hi - j)) {
            quickselect(pairs, j + 1, hi, k);
        }
        else if (k <= (hi - i + 1)) {
        }
        else {
            quickselect(pairs, lo, i - 1, k - (hi - i + 1));
        }
    }

    // Time: O(n + n), Space: O(n + n)
    vector<int> byQuickSelect(const vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int num : nums) {
            ++freqs[num];
        }

        vector<pair<int, int>> pairs(freqs.begin(), freqs.end());
        quickselect(pairs, 0, pairs.size() - 1, k);

        vector<int> ret(k);
        for (int i = 0; i < k; ++i) {
            ret[i] = pairs[pairs.size() - i - 1].first;
        }

        return ret;
    }

    vector<int> topKFrequent(const vector<int>& nums, int k) {
        //return bySort(nums, k);
        //return byBucket(nums, k);
        //return byHeap(nums, k);
        return byBinarySearch(nums, k);
        //return byQuickSelect(nums, k);
    }
};
