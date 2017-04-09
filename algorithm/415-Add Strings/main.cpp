class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            s.emplace(*iter);
        }

        if (s.size() >= 3) {
            return *(++++s.begin());
        }
        else {
            return *s.rbegin();
        }
    }


    string addStrings(string num1, string num2) {
        int count = max(num1.size(), num2.size());
        if (num1.size() < count) {
            string tmp(count - num1.size(), '0');
            tmp.reserve(count);
            tmp.insert(tmp.end(), num1.begin(), num1.end());
            num1.swap(tmp);
        }
        if (num2.size() < count) {
            string tmp(count - num2.size(), '0');
            tmp.reserve(count);
            tmp.insert(tmp.end(), num2.begin(), num2.end());
            num2.swap(tmp);
        }

        bool carry = false;
        for (int i = count - 1; i >= 0; --i) {
            int digit = num1[i] - '0' + num2[i] - '0';
            if (carry) {
                ++digit;
            }

            if (10 <= digit) {
                digit -= 10;
                carry = true;
            }
            else {
                carry = false;
            }

            num1[i] = digit + '0';
        }

        if (carry) {
            num1.insert(num1.begin(), '1');
        }

        return num1;
    }
};