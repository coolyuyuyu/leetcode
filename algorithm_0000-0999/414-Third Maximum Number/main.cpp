class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            s.emplace(*iter);
        }

        if (s.size() >= 3) {
            return *(++++s.rbegin());
        }
        else {
            return *s.rbegin();
        }
    }
};