class Solution {
public:
    // Time: O(KlogN), Space: O(N)
    int kthSmallest_Heap(const vector<vector<int>>& matrix, size_t k) {
        typedef pair<vector<int>::const_iterator, vector<int>::const_iterator> ItrPair;
        auto comp = [](const ItrPair& p1, const ItrPair& p2) {
            return (*(p1.first) > *(p2.first));
        };
        priority_queue<ItrPair, vector<ItrPair>, decltype(comp)> pq(comp); // min_heap
        for (const vector<int>& nums : matrix) {
            if (!nums.empty()) {
              pq.emplace(nums.begin(), nums.end());
            }
        }

        while (0 < k--) {
            ItrPair p = pq.top();
            pq.pop();

            ++p.first;
            if (p.first != p.second) {
                pq.push(p);
            }
        }

        return *(pq.top().first);
    }

    /*
    int countLessEqual(const vector<int>& nums, int target) {
        ++target;

        size_t lo = 0;
        size_t hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (target <= nums[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        assert(lo == hi);
        return lo;
    }

    size_t countLessEqual(const vector<vector<int>>& matrix, int target) {
        int count = 0;
        for (const vector<int> nums : matrix) {
            count += countLessEqual(nums, target);
        }
        return count;
    }

    int kthSmallest_BinarySearch(vector<vector<int>>& matrix, int k) {
        int lo = matrix.front().front();
        int hi = matrix.back().back();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int count = countLessEqual(matrix, mid);
            if (count < k) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
    */

    int kthSmallest(vector<vector<int>>& matrix, size_t k) {
        return kthSmallest_Heap(matrix, k - 1);
        //return kthSmallest_BinarySearch(matrix, k);
    }
};