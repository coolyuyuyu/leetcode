class Solution {
public:
    // Time: O(NlogN), Space: O(N)
    vector<int> findDisappearedNumbers_Set(vector<int>& nums) {
        set<int> s;
        for (int i = 1; i <= nums.size(); ++i) {
            s.insert(i);
        }
        for (int num : nums) {
            s.erase(num);
        }

        return vector<int>(s.begin(), s.end());
    }

    // Time: O(NlogN), Space: O(1)
    vector<int> findDisappearedNumbers_Sort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<int> missing;
        for (int pre = 0, i = 0; i <= nums.size(); ++i) {
            int cur = i < nums.size() ? nums[i] : (nums.size() + 1);
            for (int x = pre + 1; x < cur; ++x) {
                missing.push_back(x);
            }
            pre = cur;
        }

        return missing;
    }

    // Time: O(N), Space: O(1)
    vector<int> findDisappearedNumbers_Linear(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int j = abs(nums[i]) - 1;
            if (0 < nums[j]) {
                nums[j] = -nums[j];
            }
        }

        vector<int> missing;
        for (int i = 0; i < nums.size(); ++i) {
            if (0 < nums[i]) {
                missing.push_back(i + 1);
            }
        }

        return missing;
    }

    // Time: O(N), Space: O(1)
    vector<int> findDisappearedNumbers_CycleSort(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> missing;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != (i + 1)) {
                missing.push_back(i + 1);
            }
        }

        return missing;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //return findDisappearedNumbers_Set(nums);
        //return findDisappearedNumbers_Sort(nums);
        //return findDisappearedNumbers_Linear(nums);
        return findDisappearedNumbers_CycleSort(nums);
    }
};
