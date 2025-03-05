class Solution {
public:
    bool byBruteForce(int target) {
        vector<int> nums(1, 1);
        while (nums.back() < target) {
            nums.push_back(nums.back() * 3);
        }

        int n = nums.size();
        for (int s = 1; s < (1 << n); ++s) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if ((s >> i) & 1) {
                    sum += nums[i];
                }
            }
            if (sum == target) {
                return true;
            }
        }

        return false;
    }

    bool byMath1(int target) {
        int n = 0;
        for (int k = 1; k < target; ++n) {
            k *= 3;
        }

        for (; target; n--) {
            if (target >= std::pow(3, n)) {
                target -= std::pow(3, n);
            }
            if (target >= std::pow(3, n)) {
                return false;
            }
        }

        return true;
    }

    bool byMath2(int target) {
        for (; target; target /= 3) {
            if (target % 3 == 2) {
                return false;
            }
        }

        return true;
    }

    bool checkPowersOfThree(int n) {
        //return byBruteForce(n);
        //return byMath1(n);
        return byMath2(n);
    }
};
