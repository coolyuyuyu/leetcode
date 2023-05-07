class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> diff1(n); {
            unordered_set<int> s;
            for (int i = 0; i < n; ++i) {
                s.insert(nums[i]);
                diff1[i] = s.size();
            }
        }
        vector<int> diff2(n); {
            unordered_set<int> s;
            for (int i = n; 0 < i--;) {
                s.insert(nums[i]);
                diff2[i] = s.size();
            }
        }

        vector<int> ret(n); {
            for (int i = 0; i < n; ++i) {
                ret[i] = diff1[i];
                if ((i + 1) < n) {
                    ret[i] -= diff2[i + 1];
                }
            }
        }

        return ret;
    }
};
