class Solution {
public:
    // Min Heap. TLE
    unsigned smallestDistancePairMinHeap(vector<int>& nums, size_t k) {
        ++k;

        sort(nums.begin(), nums.end());

        priority_queue<unsigned> pq; // max heap
        for (size_t i = 0; i + 1 < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (pq.size() < k) {
                    pq.emplace(nums[j] - nums[i]);
                }
                else {
                    unsigned distance = nums[j] - nums[i];
                    if (distance < pq.top()) {
                        pq.pop();
                        pq.emplace(distance);
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return pq.top();
    }

    static size_t countDistanceNotLargerThanV1(const vector<int>& nums, unsigned distance) {
        size_t count = 0;
        for (size_t i = 0; i + 1  < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if ((nums[j] - nums[i]) <= distance) {
                    count++;
                }
                else {
                    break;
                }
            }
        }
        return count;
    }

    static size_t countDistanceNotLargerThanV2(const vector<int>& nums, unsigned distance) {
        size_t count = 0;
        for (size_t i = 0; i + 1  < nums.size(); ++i) {
            size_t j = i + 1;
            while (j < nums.size() && (nums[j] - nums[i]) <= distance) {
                ++j;
            }
            count += (j - i - 1);
        }
        return count;
    }

    static size_t countDistanceNotLargerThanV3(const vector<int>& nums, unsigned distance) {
        size_t count = 0;
        for (size_t lft = 0, rht = 1; rht < nums.size();) {
            if (nums[rht] - nums[lft] <= distance) {
                count += (rht - lft);
                ++rht;
            }
            else {
                ++lft;
            }
        }
        return count;
    }

    unsigned smallestDistancePairBinarySearch(vector<int>& nums, size_t k, size_t (*countFunc)(const vector<int>&, unsigned k)) {
        sort(nums.begin(), nums.end());

        unsigned lo = numeric_limits<unsigned>::max();
        for (size_t i = 1; i < nums.size(); ++i) {
            lo = min(lo, (unsigned)(nums[i] - nums[i - 1]));
        }
        unsigned hi = nums.back() - nums.front();
        while (lo < hi) {
            unsigned mid = lo + (hi - lo) / 2;
            size_t count = countFunc(nums, mid);
            if (count <= k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;
    }

    unsigned smallestDistancePair(vector<int>& nums, size_t k) {
        assert(0 < k);
        --k;

        //return smallestDistancePairMinHeap(nums, k);

        //return smallestDistancePairBinarySearch(nums, k, &countDistanceNotLargerThanV1);
        //return smallestDistancePairBinarySearch(nums, k, &countDistanceNotLargerThanV2);
        return smallestDistancePairBinarySearch(nums, k, &countDistanceNotLargerThanV3);
    }
};