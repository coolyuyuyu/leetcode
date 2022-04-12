class Solution {
public:
    // Time: O(NlogN), Space: O(N)
    int thirdMax_Set(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            s.insert(num);
        }

        return *(s.size() < 3 ? s.rbegin() : ++++s.rbegin());
    }

    // Time: O(N), Space: O(1)
    int thirdMax_Linear(vector<int>& nums) {
        vector<int> sorted;
        for (int num : nums) {
            auto insertedItr = std::lower_bound(sorted.begin(), sorted.end(), num);
            if (insertedItr != sorted.end() && *insertedItr == num) {
                continue; // duplicate
            }

            size_t insertedIdx = insertedItr - sorted.begin();
            if (sorted.size() < 3) {
                sorted.insert(insertedItr, num);
            }
            else if (insertedItr == sorted.begin()) {
            }
            else {
                for (auto itr = sorted.begin() + 1; itr < insertedItr; ++itr) {
                    *(itr - 1) = *itr;
                }
                *(insertedItr - 1) = num;
            }
        }

        return sorted.size() < 3 ? sorted.back() : sorted.front();
    }

    int thirdMax(vector<int>& nums) {
        //return thirdMax_Set(nums);
        return thirdMax_Linear(nums);
    }
};
