class Solution {
public:
    vector<int> twoSum1(vector<int>& numbers, int target) {
        unordered_map <int, int> hash;
        for (int i = 0; i < numbers.size(); ++i) {
            unordered_map<int, int>::const_iterator iter = hash.find(target - numbers[i]);
            if (iter != hash.end()) {
                return {iter->second + 1, i + 1};
            }
            else {
                hash.emplace(numbers[i], i);
            }
        }
        return {};
    }

    int search(const vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        size_t lo = 0;
        size_t hi = nums.size() - 1;
        while (lo <= hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                if (mid == 0) {
                    return -1;
                }
                hi = mid - 1;
            }
            else {
                assert(nums[mid] < target);
                lo = mid + 1;
            }
        }

        return -1;
    }

    vector<int> twoSum2(vector<int>& numbers, int target) {
        for (int pos1 = 0; pos1 < numbers.size(); ++pos1) {
            int num2 = target - numbers[pos1];
            int pos2 = search(numbers, num2);
            if (0 <= pos2) {
                if (pos1 == pos2) {
                    if (pos2 + 1 < numbers.size() && numbers[pos2 + 1] == num2) {
                        return {pos1 + 1, pos2 + 2};
                    }
                }
                else {
                    return {pos1 + 1, pos2 + 1};
                }
            }
        }

        return {};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        //return twoSum1(numbers, target);

        return twoSum2(numbers, target);
    }
};