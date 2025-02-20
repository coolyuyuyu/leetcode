class Solution {
public:
    string byRecursion(vector<string>& nums) {
        int n = nums.size();

        unordered_set<int> numSet;
        for (const auto& s : nums) {
            numSet.insert(std::stoi(s, nullptr, 2));
        }

        string s;
        std::function<bool()> f = [&]() {
            if (s.size() >= n) {
                return numSet.find(std::stoi(s, nullptr, 2)) == numSet.end();
            }

            for (char c : {'0', '1'}) {
                s.push_back(c);
                if (f()) {
                    return true;
                }
                s.pop_back();
            }
            return false;
        };
        f();

        return s;
    }

    string byRandom(vector<string>& nums) {
        int n = nums.size();

        unordered_set<int> numSet;
        for (const auto& s : nums) {
            numSet.insert(std::stoi(s, nullptr, 2));
        }

        int num;
        do {
            num = std::rand() % (int)pow(2, n);
        } while (numSet.find(num) != numSet.end());

        return std::bitset<16>(num).to_string().substr(16 - n);
    }

    string byCantorDiagonalArgument(vector<string>& nums) {
        int n = nums.size();

        string ret(n, '\0');
        for (int i = 0; i < n; ++i) {
            ret[i] = '1' - nums[i][i] + '0';
        }

        return ret;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        //return byRecursion(nums);
        //return byRandom(nums);
        return byCantorDiagonalArgument(nums);
    }
};
