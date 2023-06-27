class Solution {
public:
    vector<vector<int>> byBinarySearch(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();

        std::function<long(int)> cntLE = [&](int num) {
            long ret = 0;
            for (int i = 0, j = n - 1; i < m; ++i) {
                for (; 0 <= j && num < (nums1[i] + nums2[j]); --j) {
                    ;
                }
                ret += (j + 1);
            }

            return ret;
        };

        long lo = nums1.front() + nums2.front(), hi = nums1.back() + nums2.back();
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (cntLE(mid) < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        int kthVal = lo; // 1-based

        vector<vector<int>> ret;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n && (nums1[i] + nums2[j]) < kthVal; ++j) {
                ret.push_back({nums1[i], nums2[j]});
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n && (nums1[i] + nums2[j]) <= kthVal && ret.size() < k; ++j) {
                if ((nums1[i] + nums2[j]) == kthVal) {
                    ret.push_back({nums1[i], nums2[j]});
                }
            }
        }

        return ret;
    }

    vector<vector<int>> byHeap(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();

        set<pair<int, int>> visited;
        std::function<bool(const pair<int, int>&, const pair<int, int>&)> comp = [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            const auto& [i1, j1] = p1;
            const auto& [i2, j2] = p2;
            return (nums1[i1] + nums2[j1]) > (nums1[i2] + nums2[j2]);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        visited.emplace(0, 0);
        pq.emplace(0, 0);

        vector<vector<int>> ret;
        while (!pq.empty() && ret.size() < k) {
            auto [i, j] = pq.top();
            ret.push_back({nums1[i], nums2[j]});
            pq.pop();

            if ((i + 1) < m && visited.find({i + 1, j}) == visited.end()) {
                visited.emplace(i + 1, j);
                pq.emplace(i + 1, j);
            }
            if ((j + 1) < n && visited.find({i, j + 1}) == visited.end()) {
                visited.emplace(i, j + 1);
                pq.emplace(i, j + 1);
            }
        }

        return ret;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //return byBinarySearch(nums1, nums2, k);
        return byHeap(nums1, nums2, k);
    }
};
