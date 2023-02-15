class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for (int i = num.size() - 1, carry = 0; 0 <= i || 0 < k || carry; --i) {
            int v = (0 <= i ? num[i] : 0) + (k % 10) + carry;

            k /= 10;
            carry = (10 <= v);

            v %= 10;
            if (0 <= i) {
                num[i] = v;
            }
            else {
                num.insert(num.begin(), v);
            }
        }

        return num;
    }
};
