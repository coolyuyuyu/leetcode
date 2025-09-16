class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ret;
        for (int x : nums) {
            while (!ret.empty() && std::gcd(ret.back(), x) > 1) {
                int y = ret.back();
                ret.pop_back();

                x = 1LL * y * x / std::gcd(y, x);
            }
            ret.push_back(x);
        }

        return ret;
    }
};
