class Solution {
public:
    int gcd(int m, int n){
        while(n!=0) {
            int tmp = m % n;
            m = n;
            n = tmp;
        }
        return m;
    }

    int findGCD(vector<int>& nums) {
       auto p = std::minmax_element(nums.begin(), nums.end());
        int min = *p.first, max = *p.second;

        return gcd(min, max);
    }
};
