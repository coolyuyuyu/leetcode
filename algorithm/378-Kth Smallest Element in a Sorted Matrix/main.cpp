class Solution {
public:
    int kthSmallestPriorityQueue(const vector<vector<int>>& matrix, int k) {
        typedef pair<vector<int>::const_iterator, vector<int>::const_iterator> ItrPair;
        auto comp = [](const ItrPair& lft, const ItrPair& rht) { return *(lft.first) > *(rht.first); };

        priority_queue<ItrPair, vector<ItrPair>, decltype(comp)> pq(comp);
        for (const vector<int>& vals : matrix) {
            if (!vals.empty()) {
                pq.emplace(vals.begin(), vals.end());
            }
        }

        while (k > 1) {
            ItrPair itrPair = pq.top();
            pq.pop();

            --k;

            ++itrPair.first;
            if (itrPair.first != itrPair.second) {
                pq.emplace(itrPair.first, itrPair.second);
            }
        }

        return *(pq.top().first);
    }

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

    int kthSmallestBinarySearch(vector<vector<int>>& matrix, int k) {
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

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //return kthSmallestPriorityQueue(matrix, k);

        return kthSmallestBinarySearch(matrix, k);
    }
};